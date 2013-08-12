/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created: Sun Apr 8 19:23:21 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Help
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Help)
    {
        if (Help->objectName().isEmpty())
            Help->setObjectName(QString::fromUtf8("Help"));
        Help->resize(305, 352);
        Help->setStyleSheet(QString::fromUtf8("#labelTitle {\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"#textBrowser {\n"
"	background-color: rgba(0,0,0,0);\n"
"}"));
        verticalLayout = new QVBoxLayout(Help);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelTitle = new QLabel(Help);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));

        verticalLayout->addWidget(labelTitle);

        textBrowser = new QTextBrowser(Help);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setFocusPolicy(Qt::WheelFocus);
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(textBrowser);


        retranslateUi(Help);

        QMetaObject::connectSlotsByName(Help);
    } // setupUi

    void retranslateUi(QWidget *Help)
    {
        Help->setWindowTitle(QApplication::translate("Help", "Form", 0, QApplication::UnicodeUTF8));
        labelTitle->setText(QApplication::translate("Help", "Help", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">smsServer is an application that allows forwarding received sms and mms messages to any web server over Wi-Fi or 3G networks. <br /><br />Server post URL defines address of your incoming SMS message parser.<br /></span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Status URL is called by smsServer to update device status information.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0p"
                        "x; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"><br />Phone Key is optional property that will be sent to the server. You can use this property to identify the device that received text message or protect your request handler from unauthorized access.<br /><br />For more details, please, visit </span><span style=\" font-size:8pt; font-weight:600;\">mindomobile.com</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Help: public Ui_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
