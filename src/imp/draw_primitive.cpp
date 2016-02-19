#include "../QRockyStyle.h"
#include <QPainter>
#include <QStyleOption>
#include "../QRockyButton.h"

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

static void drawFrame(QStyle::PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget, qreal em) {
    int x, y, w, h;
    option->rect.getRect(&x, &y, &w, &h);
    auto btn = dynamic_cast<const QRockyButton *>(widget);
    auto cb = btn ? btn->combineBorders() : QRockyStyle::Combine_None;
    auto path = QRockyStyle::makeRoundedRect(QRectF(x, y, w, h), em/4, em/4, em/16, cb);
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
    painter->strokePath(path, painter->pen());
    painter->restore();
}

static void drawPanelButton(QStyle::PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget, qreal em) {
    int x, y, w, h;
    option->rect.getRect(&x, &y, &w, &h);
    auto btn = dynamic_cast<const QRockyButton *>(widget);
    auto cb = btn ? btn->combineBorders() : QRockyStyle::Combine_None;
    auto path = QRockyStyle::makeRoundedRect(QRectF(x, y, w, h), em/4, em/4, em/16, cb);
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    if(option->state & (QStyle::State_On | QStyle::State_Sunken)) {
        painter->setBrush(option->palette.midlight());
    } else {
        painter->setBrush(option->palette.button());
    }
    painter->fillPath(path, painter->brush());
    painter->restore();
    drawFrame(element, option, painter, widget, em);
}
