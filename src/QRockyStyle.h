#pragma once

#include <QProxyStyle>

#ifdef QROCKYSTYLE_EXPORT
#define QROCKYSTYLE_DLLSPEC Q_DECL_EXPORT
#else
#define QROCKYSTYLE_DLLSPEC Q_DECL_IMPORT
#endif

class QROCKYSTYLE_DLLSPEC QRockyStyle : public QProxyStyle {
    Q_OBJECT

public:
    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = nullptr) const;
};
