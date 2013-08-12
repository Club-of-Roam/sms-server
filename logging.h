#ifndef LOGGING_H
#define LOGGING_H

#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QTime>

namespace Ui {
    class Logging;
}

class Logging : public QWidget
{
    Q_OBJECT

public:
    explicit Logging(QWidget *parent = 0);
    ~Logging();

    void createOptionsMenu();

private slots:
    void menuClearLog();
    void menuBack();

public slots:
    void coreLogging(QString message);

Q_SIGNALS:
    void menuBackClicked();

private:
    Ui::Logging *ui;

    QAction *clearLogKey;
    QAction *backKey;
    QTime currentTime;
};

#endif // LOGGING_H
