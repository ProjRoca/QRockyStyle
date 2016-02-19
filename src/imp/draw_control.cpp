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
#include <QPainter>
#include <QStyleOption>

static void drawProgressBarGroove(QStyle::ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget, qreal em);
static void drawProgressBarContents(QStyle::ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget, qreal em);

void QRockyStyle::drawControl(QStyle::ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const {
    qreal em = QRockyStyle::em(widget);

    if(element == QStyle::CE_ProgressBarGroove) {
        drawProgressBarGroove(element, option, painter, widget, em);
    } else if(element == QStyle::CE_ProgressBarContents) {
        drawProgressBarContents(element, option, painter, widget, em);
    } else {
        QProxyStyle::drawControl(element, option, painter, widget);
    }
}

static void drawProgressBarGroove(QStyle::ControlElement, const QStyleOption *option, QPainter *painter, const QWidget *, qreal em) {
    int x, y, w, h;
    option->rect.getRect(&x, &y, &w, &h);
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::NoPen);
    painter->setBrush(option->palette.base());
    painter->drawRoundedRect(QRectF(x, y, w, h), em/4, em/4);
    painter->restore();
}

static void drawProgressBarContents(QStyle::ControlElement, const QStyleOption *option, QPainter *painter, const QWidget *, qreal em) {
    int x, y, w, h;
    option->rect.getRect(&x, &y, &w, &h);
    auto bar = qstyleoption_cast<const QStyleOptionProgressBar *>(option);
    if(bar->minimum != bar->maximum) {
        QRectF rect;
        if(bar->orientation != Qt::Vertical) {
            rect = QRectF(x, y, w*1.0*(bar->progress - bar->minimum)/(bar->maximum - bar->minimum), h);
        } else {
            qreal subh = h*1.0*(bar->progress - bar->minimum)/(bar->maximum - bar->minimum);
            rect = QRectF(x+h-subh, y, w, subh);
        }
        painter->save();
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setPen(Qt::NoPen);
        painter->setBrush(option->palette.highlight());
        painter->setClipRect(rect);
        painter->drawRoundedRect(QRectF(x, y, w, h), em/4, em/4);
        painter->restore();
    } else {
        // Does not have a indeterminate style
        Q_ASSERT(bar->minimum != bar->maximum);
    }
}
