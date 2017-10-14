#
# UniECU
#

TEMPLATE = app
TARGET = UniECU
DEPENDPATH += . src ui
INCLUDEPATH += . src

UI_DIR = ui

CONFIG += debug_and_release warn_on thread

DESTDIR = bin
OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc

CONFIG(debug, debug|release) {
    DESTDIR = bin/debug
    OBJECTS_DIR = .obj/debug
    MOC_DIR = .moc/debug
    RCC_DIR = .rcc/debug
} else {
    DESTDIR = bin
    OBJECTS_DIR = .obj
    MOC_DIR = .moc
    RCC_DIR = .rcc
}


# Input main
SOURCES += main.cpp

#Input UniECU class
HEADERS += UniECU.h
FORMS += ui/UniECU.ui
SOURCES += UniECU.cpp OpenClosePort.cpp ConnectDisconnect.cpp Communication.cpp GuiCondition.cpp

#Input Common classes
SOURCES += Wait.cpp DisplayCommunication.cpp SetParameter.cpp

#Input serial port stuff
HEADERS += Serial.h
SOURCES += Serial.cpp 

#Input KW82 stuff
SOURCES += KW82ConnectDisconnect.cpp KW82Communication.cpp  KW82DataTransfer.cpp

#Input KW2000 stuff
SOURCES += KW2000ConnectDisconnect.cpp KW2000Communication.cpp KW2000DataTransfer.cpp

#Input Search ECU stuff
SOURCES += SearchECU.cpp




