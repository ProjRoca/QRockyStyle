/*
    Rocaloid
    Copyright (C) 2015 StarBrilliant <m13253@hotmail.com>

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
#pragma once
#include "QRockyStyle.h"
#include <QPushButton>

class QROCKYSTYLE_DLLSPEC QRockyButton : public QPushButton {
    Q_OBJECT

public:
    QRockyButton(QWidget *parent = nullptr) :
        QPushButton(parent) {
    }
    QRockyButton(const QString &text, QWidget *parent = nullptr) :
        QPushButton(text, parent) {
    }
    QRockyButton(const QIcon &icon, const QString &text, QWidget *parent = nullptr) :
        QPushButton(icon, text, parent) {
    }

    QRockyStyle::CombineBorders combineBorders() const {
        return data_combineBorders;
    }
    void setCombineBorders(QRockyStyle::CombineBorders cb) {
        data_combineBorders = cb;
    }

    void setMinMaxHeight(int h) {
        setMinimumHeight(h);
        setMaximumHeight(h);
    }
    void setMinMaxSize(const QSize &size) {
        setMinimumSize(size);
        setMaximumSize(size);
    }
    void setMinMaxSize(int w, int h) {
        setMinimumSize(w, h);
        setMaximumSize(w, h);
    }
    void setMinMaxWidth(int w) {
        setMinimumWidth(w);
        setMaximumWidth(w);
    }

private:
    QRockyStyle::CombineBorders data_combineBorders = QRockyStyle::Combine_None;
};
