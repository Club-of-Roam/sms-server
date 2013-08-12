#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server),
    isRunning(false)
{
    ui->setupUi(this);

    /* get settings */
    QSettings settings("Mindo Mobile", "smsServer");
    QString serverPostUrl = settings.value("app/serverPostUrl", "http://").toString();
    QString statusUrl = settings.value("app/statusUrl", "http://").toString();
    QString phoneId = settings.value("app/phoneId", "").toString();

    /* update view */
    ui->serverPostUrlEdit->setText(serverPostUrl);
    ui->statusUrlEdit->setText(statusUrl);
    ui->phoneIdEdit->setText(phoneId);

    /* Create options menu */
    this->createOptionsMenu();
}

Server::~Server()
{
    delete ui;
}

void Server::createOptionsMenu()
{
    menu = new QMenu(this);

    if (isRunning) {
        menu->addAction("Stop Service", this, SLOT(menuStopService()));
    } else {
        menu->addAction("Start Service", this, SLOT(menuStartService()));
    }

    menu->addAction("Save Settings", this, SLOT(menuSaveSettings()));
    menu->addAction("MMS Test",      this, SLOT(menuTestMMS()));
    menu->addAction("Show Log",      this, SLOT(menuShowLog()));

    /* option key */
    optionKey = new QAction("Options", this);
    optionKey->setSoftKeyRole(QAction::PositiveSoftKey);
    optionKey->setMenu(menu);
    addAction(optionKey);

    /* exit key */
    exitKey = new QAction("Exit", this);
    exitKey->setSoftKeyRole(QAction::NegativeSoftKey);
    addAction(exitKey);

    connect(exitKey, SIGNAL(triggered()), this, SLOT(menuExit()));
}

void Server::menuExit()
{
    emit menuExitClicked();
}

void Server::menuShowLog()
{
    emit menuShowLogClicked();
}

void Server::menuSaveSettings()
{
    QSettings settings("Mindo Mobile", "smsServer");
    settings.setValue("app/serverPostUrl", ui->serverPostUrlEdit->text());
    settings.setValue("app/statusUrl", ui->statusUrlEdit->text());
    settings.setValue("app/phoneId", ui->phoneIdEdit->text());

    QMessageBox msgBox;
    msgBox.setText("Settings successfully updated!");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}

void Server::menuStartService()
{
    isRunning = true;
    emit menuStartServiceClicked();
}

void Server::menuStopService()
{
    isRunning = false;
    emit menuStopServiceClicked();
}

void Server::menuTestMMS()
{
    QString msisdn = "+37065100000";
    QString msg = "MMS test message!";
    QString filename = "mms-test.png";
    QPixmap pixmap = QPixmap(":/mms-test.png");

    emit sendTestMMS(msisdn, msg, filename, pixmap);
}
