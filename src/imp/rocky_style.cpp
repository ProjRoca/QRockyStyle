#include "../QRockyStyle.h"
#include <QApplication>
#include <QFontInfo>
#include <QWidget>
#include <iostream>

QRockyStyle::QRockyStyle() :
    QProxyStyle("Fusion") {
    palette.setColor(QPalette::Window,        rgb(0x262d33));
    palette.setColor(QPalette::WindowText,    rgb(0xffffff));
    palette.setColor(QPalette::Base,          rgb(0x424f59));
    palette.setColor(QPalette::AlternateBase, rgb(0xbbc6d0));
    palette.setColor(QPalette::Text,          rgb(0xffffff));
    palette.setColor(QPalette::Button,        rgb(0x363e40));
    palette.setColor(QPalette::ButtonText,    rgb(0xffffff));
    palette.setColor(QPalette::BrightText,    rgb(0x000000));
    palette.setColor(QPalette::Light,         rgb(0xe5e5e5));
    palette.setColor(QPalette::Midlight,      rgb(0x9fa0a0));
    palette.setColor(QPalette::Mid,           rgb(0x535353));
    palette.setColor(QPalette::Dark,          rgb(0x3a3e3f));
    palette.setColor(QPalette::Shadow,        rgb(0x262d33));
}

QRockyStyle::~QRockyStyle() {
}

qreal QRockyStyle::em(const QWidget *widget) {
    if(widget) {
        return widget->fontInfo().pixelSize();
    } else {
        auto app = static_cast<QApplication *>(QApplication::instance());
        if(app) {
            return QFontInfo(app->font()).pixelSize();
        } else {
            return 16;
        }
    }
}

void QRockyStyle::polish(QWidget *widget) {
    widget->setPalette(palette);
}

void QRockyStyle::polish(QPalette &pal) {
    pal = palette;
}

void QRockyStyle::polish(QApplication *app) {
    app->setPalette(palette);
}

QPalette QRockyStyle::standardPalette() const {
    return palette;
}

QColor QRockyStyle::rgb(quint32 rgb) {
    return QColor(rgb >> 16, quint8(rgb >> 8), quint8(rgb));
}
