# Add files and directories to ship with the application 
# by adapting the examples below.
# file1.source = myfile
# dir1.source = mydir
DEPLOYMENTFOLDERS = # file1 dir1

symbian:TARGET.UID3 = 0xE46DF75D
#0x2005ff93

# Smart Installer package's UID
# This UID is from the protected range 
# and therefore the package will fail to install if self-signed
# By default qmake uses the unprotected range value if unprotected UID is defined for the application
# and 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
#symbian:TARGET.CAPABILITY +=

# If your application uses the Qt Mobility libraries, uncomment
# the following lines and add the respective components to the 
# MOBILITY variable. 

QT += network

symbian {
TARGET.CAPABILITY = ReadUserData \
    WriteUserData \
    ReadDeviceData \
    WriteDeviceData \
    NetworkServices
}

CONFIG += mobility
MOBILITY += messaging

SOURCES += main.cpp mainwindow.cpp \
    server.cpp \
    logging.cpp \
    core.cpp
HEADERS += mainwindow.h \
    server.h \
    logging.h \
    core.h
FORMS += mainwindow.ui \
    server.ui \
    logging.ui

ICON = smsServer.svg

# Please do not modify the following two lines. Required for deployment.
include(deployment.pri)
qtcAddDeployment()

RESOURCES += \
    res.qrc
