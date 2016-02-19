TARGET		= QRockyStyleDemo
TEMPLATE	= app
CONFIG		+= c++11
QT		+= widgets
DEPENDPATH	+= ..
INCLUDEPATH	+= ../src
LIBS		+= -L.. -lQRockyStyle

SOURCES += \
	src/imp/main.cpp \
	src/imp/main_window.cpp

HEADERS += \
	src/main_window.h
