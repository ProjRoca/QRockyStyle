#include "../QRockyStyle.h"
#include <QPainter>
#include <QStyleOption>

static void drawProgressBarGroove(QStyle::ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget, qreal em, QPalette palette);
static void drawProgressBarContents(QStyle::ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget, qreal em, QPalette palette);

void QRockyStyle::drawControl(QStyle::ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const {
    qreal em = QRockyStyle::em(widget);
    auto palette = widget ? widget->palette() : this->palette;

    if(element == QStyle::CE_ProgressBarGroove) {
        drawProgressBarGroove(element, option, painter, widget, em, palette);
    } else if(element == QStyle::CE_ProgressBarContents) {
        drawProgressBarContents(element, option, painter, widget, em, palette);
    } else {
        QProxyStyle::drawControl(element, option, painter, widget);
    }
}

static void drawProgressBarGroove(QStyle::ControlElement, const QStyleOption *option, QPainter *painter, const QWidget *, qreal em, QPalette palette) {
    int x, y, w, h;
    option->rect.getRect(&x, &y, &w, &h);
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::NoPen);
    painter->setBrush(palette.base());
    painter->drawRoundedRect(QRectF(x, y, w, h), em/4, em/4);
    painter->restore();
}

static void drawProgressBarContents(QStyle::ControlElement, const QStyleOption *option, QPainter *painter, const QWidget *, qreal em, QPalette palette) {
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
        painter->setBrush(palette.highlight());
        painter->setClipRect(rect);
        painter->drawRoundedRect(QRectF(x, y, w, h), em/4, em/4);
        painter->restore();
    } else {
        // Does not have a indeterminate style
        Q_ASSERT(bar->minimum != bar->maximum);
    }
}
