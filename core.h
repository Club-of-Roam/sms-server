#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <QSettings>
#include <QPointer>
#include <QMessageManager>
#include <QMessageId>
#include <QMessage>
#include <QPixmap>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QBuffer>

QTM_USE_NAMESPACE

class Core : public QObject
{
    Q_OBJECT
public:
    explicit Core(QObject *parent = 0);

public slots:
    void messageAdded(const QMessageId&, const QMessageManager::NotificationFilterIdSet&);
    void forwardMessage(QString msisdn, QString msg, QString filename, QPixmap image);
    void updateStatusUrl();
    void replyFinished(QNetworkReply *reply);

    void startCore();
    void stopCore();

Q_SIGNALS:
    void coreLogging(QString);

private:
    QPointer < QMessageManager > m_manager;
    QMessageManager::NotificationFilterIdSet m_notifFilterSet;
    QMessageId m_messageId;

    QNetworkAccessManager *m_network_manager;
};

#endif // CORE_H
