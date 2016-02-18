#include "../QRockyStyle.h"
#include <QStyleOption>

QRect QRockyStyle::subElementRect(QStyle::SubElement element, const QStyleOption *option, const QWidget *widget) const {
    if(element == QStyle::SE_PushButtonFocusRect) {
        return option->rect;
    } else {
        return QProxyStyle::subElementRect(element, option, widget);
    }
}
