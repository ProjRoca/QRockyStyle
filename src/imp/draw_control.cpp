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

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen((widget ? widget->palette() : palette).midlight(), m/16));
    if(option->state & (QStyle::State_On | QStyle::State_Sunken)) {
        painter->setBrush((widget ? widget->palette() : palette).midlight());
    } else {
        painter->setBrush((widget ? widget->palette() : palette).button());
    }
    painter->drawRoundedRect(QRectF(x+m/16, y+m/16, w-m/8, h-m/8), m/4, m/4);
}
