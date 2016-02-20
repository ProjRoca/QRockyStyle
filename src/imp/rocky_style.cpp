/*
    Project Roca
    Copyright (C) 2016 StarBrilliant <m13253@hotmail.com>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3.0 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this program.  If not,
    see <http://www.gnu.org/licenses/>.
*/
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
    palette.setColor(QPalette::Light,         rgb(0x9fa0a0));
    palette.setColor(QPalette::Midlight,      rgb(0x667b80));
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

QPalette QRockyStyle::standardPalette() const {
    return palette;
}

QColor QRockyStyle::rgb(quint32 rgb) {
    return QColor(rgb >> 16, quint8(rgb >> 8), quint8(rgb));
}

QPainterPath QRockyStyle::makeRoundedRect(QRectF base_rect, qreal rx, qreal ry, qreal width, CombineBorders cb) {
    QPainterPath path;

    if(!(cb & Combine_Top)) {
        base_rect.setTop(base_rect.top() + width/2);
    }
    if(!(cb & Combine_Left)) {
        base_rect.setLeft(base_rect.left() + width/2);
    }
    if(!(cb & Combine_Bottom)) {
        base_rect.setBottom(base_rect.bottom() - width/2);
    }
    if(!(cb & Combine_Right)) {
        base_rect.setRight(base_rect.right() - width/2);
    }

    if(cb & (Combine_Top | Combine_Left)) {
        path.moveTo(QPointF(base_rect.left(), base_rect.top()));
    } else {
        path.moveTo(QPointF(base_rect.left() + rx, base_rect.top()));
        path.arcTo(QRectF(base_rect.left(), base_rect.top(), rx*2, ry*2), 90.0, 90.0);
    }
    if(cb & (Combine_Left | Combine_Bottom)) {
        path.lineTo(QPointF(base_rect.left(), base_rect.bottom()));
    } else {
        path.lineTo(QPointF(base_rect.left(), base_rect.bottom() - ry));
        path.arcTo(QRectF(base_rect.left(), base_rect.bottom() - ry*2, rx*2, ry*2), -180.0, 90.0);
    }
    if(cb & (Combine_Bottom | Combine_Right)) {
        path.lineTo(QPointF(base_rect.right(), base_rect.bottom()));
    } else {
        path.lineTo(QPointF(base_rect.right() - rx, base_rect.bottom()));
        path.arcTo(QRectF(base_rect.right() - rx*2, base_rect.bottom() - ry*2, rx*2, ry*2), -90.0, 90.0);
    }
    if(cb & (Combine_Right | Combine_Top)) {
        path.lineTo(QPointF(base_rect.right(), base_rect.top()));
    } else {
        path.lineTo(QPointF(base_rect.right(), base_rect.top() + ry));
        path.arcTo(QRectF(base_rect.right() - rx*2, base_rect.top(), rx*2, ry*2), 0.0, 90.0);
    }
    path.closeSubpath();
    return path;
}
