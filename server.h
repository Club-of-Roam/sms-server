#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QMessageBox>
#include <QSettings>
#include <QMenu>
#include <QAction>
#include <QPixmap>

namespace Ui {
    class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();

    void createOptionsMenu();

private Q_SLOTS:
    void menuShowLog();
    void menuExit();
    void menuSaveSettings();
    void menuStartService();
    void menuStopService();
    void menuTestMMS();

Q_SIGNALS:
    void menuShowLogClicked();
    void menuExitClicked();
    void menuStartServiceClicked();
    void menuStopServiceClicked();
    void sendTestMMS(QString, QString, QString, QPixmap);

private:
    Ui::Server *ui;

    bool isRunning;
    QMenu *menu;
    QAction *optionKey;
    QAction *exitKey;

};

#endif // SERVER_H
