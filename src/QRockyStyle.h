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
    QRockyStyle();
    ~QRockyStyle();
    void polish(QWidget *widget);
    void polish(QPalette &palette);
    void polish(QApplication *app);
    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = nullptr) const;
    void drawPrimitive(PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = nullptr) const;
    QPalette standardPalette() const;

private:
    QPalette palette;
    static QColor rgb(quint32 rgb);
    static qreal em(const QWidget *widget);
    void drawPushButtonBevel(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
};
