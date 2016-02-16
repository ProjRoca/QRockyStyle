TARGET		= QRockyStyle
TEMPLATE	= lib
CONFIG		+= c++11
QT		+= widgets
DEFINE		+= QROCKYSTYLE_EXPORT

SOURCES += \
	src/imp/draw_control.cpp

HEADERS += \
	src/QRockyStyle.h
