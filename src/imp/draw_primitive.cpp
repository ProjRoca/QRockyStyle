#include "../QRockyStyle.h"
#include <QPainter>
#include <QStyleOption>

static void drawFrame(QStyle::PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget, qreal em);
static void drawPanelButton(QStyle::PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget, qreal em);

void QRockyStyle::drawPrimitive(QStyle::PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const {
    qreal em = QRockyStyle::em(widget);

    if(element == QStyle::PE_Frame) {
        drawFrame(element, option, painter, widget, em);
    } else if(element == QStyle::PE_FrameLineEdit) {
        drawFrame(element, option, painter, widget, em);
    } else if(element == QStyle::PE_PanelButtonCommand) {
        drawPanelButton(element, option, painter, widget, em);
    } else if(element == QStyle::PE_PanelButtonTool) {
        drawPanelButton(element, option, painter, widget, em);
    } else {
        QProxyStyle::drawPrimitive(element, option, painter, widget);
    }
}

static void drawFrame(QStyle::PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *, qreal em) {
    int x, y, w, h;
    option->rect.getRect(&x, &y, &w, &h);
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    if(option->state & QStyle::State_Editing) {
        painter->setPen(QPen(option->palette.highlight(), em/16));
    } else if((option->state & QStyle::State_HasFocus) && (option->state & QStyle::State_KeyboardFocusChange)) {
        painter->setPen(QPen(option->palette.highlight(), em/16));
    } else if((option->state & QStyle::State_HasFocus) && (element == QStyle::PE_FrameLineEdit)) {
        painter->setPen(QPen(option->palette.highlight(), em/16));
    } else {
        painter->setPen(QPen(option->palette.midlight(), em/16));
    }
    painter->setBrush(Qt::NoBrush);
    painter->drawRoundedRect(QRectF(x+em/16, y+em/16, w-em/8, h-em/8), em/4, em/4);
    painter->restore();
}

static void drawPanelButton(QStyle::PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget, qreal em) {
    int x, y, w, h;
    option->rect.getRect(&x, &y, &w, &h);
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::NoPen);
    if(option->state & (QStyle::State_On | QStyle::State_Sunken)) {
        painter->setBrush(option->palette.midlight());
    } else {
        painter->setBrush(option->palette.button());
    }
    painter->drawRoundedRect(QRectF(x+em/16, y+em/16, w-em/8, h-em/8), em/4, em/4);
    painter->restore();
    drawFrame(element, option, painter, widget, em);
}
