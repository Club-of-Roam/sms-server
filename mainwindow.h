#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QStackedWidget>
#include "server.h"
#include "logging.h"
#include "core.h"

QTM_USE_NAMESPACE

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };

    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    void setOrientation(ScreenOrientation orientation);
    void showExpanded();

private:
    Ui::MainWindow *ui;
    QStackedWidget *w;
    Server *server;
    Logging *logging;
    Core *core;

public slots:
    void showServer();
    void showLog();
};

#endif // MAINWINDOW_H
