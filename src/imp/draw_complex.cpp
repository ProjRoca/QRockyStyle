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

