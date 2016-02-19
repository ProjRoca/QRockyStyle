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

void QRockyStyle::drawComplexControl(ComplexControl control, const QStyleOptionComplex *option, QPainter *painter, const QWidget *widget) const {
    qreal em = QRockyStyle::em(widget);
    auto palette = widget ? widget->palette() : this->palette;

    if(control == QStyle::CC_ToolButton) {
        QProxyStyle::drawComplexControl(control, option, painter, widget);
    } else {
        QProxyStyle::drawComplexControl(control, option, painter, widget);
    }
}

