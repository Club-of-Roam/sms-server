#include "logging.h"
#include "ui_logging.h"

Logging::Logging(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Logging)
{
    ui->setupUi(this);

    this->createOptionsMenu();
}

Logging::~Logging()
{
    delete ui;
}

void Logging::createOptionsMenu()
{
    /* clear log */
    clearLogKey = new QAction("Clear Log", this);
    clearLogKey->setSoftKeyRole(QAction::PositiveSoftKey);
    addAction(clearLogKey);

    /* back */
    backKey = new QAction("Back", this);
    backKey->setSoftKeyRole(QAction::NegativeSoftKey);
    addAction(backKey);

    connect(backKey, SIGNAL(triggered()), this, SLOT(menuBack()));
    connect(clearLogKey, SIGNAL(triggered()), this, SLOT(menuClearLog()));
}

void Logging::menuBack() {
    emit menuBackClicked();
}

void Logging::menuClearLog()
{
    ui->logText->clear();
}

void Logging::coreLogging(QString message)
{
    QStringList logs = ui->logText->toPlainText().split("\n");

    currentTime = QTime::currentTime();

    ui->logText->clear();
    ui->logText->append(QString("[%1] %2").arg(currentTime.toString("hh:mm:ss")).arg(message.remove("\n")));
    for(int i=0; i<9 && i<logs.length(); i++) {
        ui->logText->append(logs.at(i));
    }
}
