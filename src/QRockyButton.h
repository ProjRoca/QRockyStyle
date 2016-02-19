#pragma once

#include "QRockyStyle.h"
#include <QPushButton>

class QRockyButton : public QPushButton {
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

private:
    QRockyStyle::CombineBorders data_combineBorders = QRockyStyle::Combine_None;
};
