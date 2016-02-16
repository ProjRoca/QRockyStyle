#include "../QRockyStyle.h"
#include <QPainter>
#include <QStyleOption>

void QRockyStyle::drawPrimitive(PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const {
    QProxyStyle::drawPrimitive(element, option, painter, widget);
}

