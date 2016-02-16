#include "../QRockyStyle.h"
#include <QPainter>
#include <QStyleOption>

void QRockyStyle::drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const {
    if(element == CE_PushButtonBevel) {
        drawPushButtonBevel(element, option, painter, widget);
    } else {
        QProxyStyle::drawControl(element, option, painter, widget);
    }
}

void QRockyStyle::drawPushButtonBevel(ControlElement, const QStyleOption *option, QPainter *painter, const QWidget *widget) const {
    qreal m = em(widget);
    int x, y, w, h;
    option->rect.getRect(&x, &y, &w, &h);

    painter->setClipping(false);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen((widget ? widget->palette() : palette).midlight(), m/14));
    painter->setBrush((widget ? widget->palette() : palette).button());
    painter->drawRoundedRect(QRectF(x+m/14, y+m/14, w-m/7, h-m/7), m*3/7, m*3/7);
}
