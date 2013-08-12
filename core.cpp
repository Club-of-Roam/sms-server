#include "core.h"

Core::Core(QObject *parent) :
    QObject(parent)
{
}

void Core::startCore()
{
    // Setup network
    m_network_manager = new QNetworkAccessManager();

    // Add SMS and MMS filter for message manager
    m_manager = new QMessageManager();
    m_notifFilterSet.insert(m_manager->registerNotificationFilter(QMessageFilter::byType(QMessage::Sms)));
    m_notifFilterSet.insert(m_manager->registerNotificationFilter(QMessageFilter::byType(QMessage::Mms)));

    connect(m_manager, SIGNAL(messageAdded(const QMessageId&,const QMessageManager::NotificationFilterIdSet&)),
                this, SLOT(messageAdded(const QMessageId&, const QMessageManager::NotificationFilterIdSet&)));

    connect(m_network_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));

    // Start status updater
    QTimer::singleShot(300000, this, SLOT(updateStatusUrl())); // 5 minutes

    emit coreLogging("server started.");
}

void Core::stopCore()
{
    m_manager->deleteLater();
    m_network_manager->deleteLater();

    emit coreLogging("server was stopped.");
}

void Core::messageAdded(const QMessageId& id, const QMessageManager::NotificationFilterIdSet& matchingFilterIds)
{
    QMessage message = m_manager->message(id);
    QString msisdn = message.from().addressee();
    QString msg, filename;
    QPixmap img;

    if (message.type() == QMessage::Mms) {
        // take the first attachement
        msg = QString(message.subject());
        QMessageContentContainerIdList list = message.attachmentIds();
        if (!list.isEmpty()) {
            for (int i=0; i<list.count(); i++) {
                QMessageContentContainer container = message.find(list[i]);
                if (container.isContentAvailable() && container.contentType() == "image") {
                    img.loadFromData(container.content());
                    filename = container.suggestedFileName();
                    break;
                }
            }
        }

        // forward mms message
        this->forwardMessage(msisdn, msg, filename, img);
    } else {
        // get the content
        msg = message.textContent();

        // forward sms message
        this->forwardMessage(msisdn, msg, NULL, NULL);
    }

    // log message
    emit coreLogging(QString("[%1] %2").arg(msisdn).arg(msg));

    // clean up
    m_manager->removeMessage(id);
}

void Core::forwardMessage(QString msisdn, QString msg, QString filename, QPixmap img)
{
    QSettings s("Mindo Mobile", "smsServer");

    QString messageType = (filename != NULL)?"MMS":"SMS";
    QString fileExtention = filename.split(".").last();

    QNetworkRequest request(QUrl(s.value("app/serverPostUrl").toString()));
    QString bound="margin"; //name of the boundary

    // Message Type
    QByteArray data(QString("--" + bound + "\r\n").toAscii());
    data.append("Content-Disposition: form-data; name=\"type\"\r\n\r\n");
    data.append(QString("%1\r\n").arg(messageType));
    data.append("--" + bound + "\r\n");

    // Msisdn
    data.append("Content-Disposition: form-data; name=\"msisdn\"\r\n\r\n");
    data.append(QString("%1\r\n").arg(msisdn));
    data.append("--" + bound + "\r\n");

    // Message
    data.append("Content-Disposition: form-data; name=\"msg\"\r\n\r\n");
    data.append(QString("%1\r\n").arg(msg));
    data.append("--" + bound + "\r\n");

    // Phone ID
    data.append("Content-Disposition: form-data; name=\"id\"\r\n\r\n");
    data.append(QString("%1\r\n").arg(s.value("app/phoneId").toString()));
    data.append("--" + bound + "\r\n");

    // Attachement (if applicable)
    if (filename != NULL) {
        data.append(QString("Content-Disposition: form-data; name=\"file\"; filename=\"%1\"\r\n").arg(filename));
        data.append(QString("Content-Type: image/%1\r\n\r\n").arg(fileExtention));

        QImage image = img.toImage();
        QByteArray ba;
        QBuffer buffer(&ba);
        buffer.open(QIODevice::WriteOnly);
        image.save(&buffer, fileExtention.toAscii().data());
        //delete image;

        data.append(ba);
        data.append("\r\n");
        data.append("--" + bound + "--\r\n");
    }

    request.setRawHeader(QString("Content-Type").toAscii(), QString("multipart/form-data; boundary=" + bound).toAscii());
    request.setRawHeader(QString("Content-Length").toAscii(), QString::number(data.length()).toAscii());

    m_network_manager->post(request, data);
}

void Core::updateStatusUrl()
{
    QSettings s("Mindo Mobile", "smsServer");
    QNetworkRequest request(QUrl(s.value("app/statusUrl").toString()));
    m_network_manager->get(request);

    QTimer::singleShot(300000, this, SLOT(updateStatusUrl())); // 5 minutes
}

void Core::replyFinished(QNetworkReply* reply)
{
    if(reply->error() == QNetworkReply::NoError) {
        emit coreLogging(QString("Server reply: %1").arg(reply->readAll().data()));
    } else {
        emit coreLogging(QString("Remote server error."));
    }

    reply->deleteLater();
}
