TARGET		= QRockyStyle
TEMPLATE	= lib
CONFIG		+= c++11
QT		+= widgets
DEFINE		+= QROCKYSTYLE_EXPORT

SOURCES += \
	src/imp/rocky_style.cpp \
	src/imp/draw_control.cpp src/imp/draw_primitive.cpp

HEADERS += \
	src/QRockyStyle.h
