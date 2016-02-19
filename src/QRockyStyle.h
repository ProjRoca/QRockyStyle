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

    static qreal em(const QWidget *widget);

    void polish(QWidget *widget);
    void polish(QPalette &palette);
    void polish(QApplication *app);
    QPalette standardPalette() const;

    void drawComplexControl(QStyle::ComplexControl control, const QStyleOptionComplex *option, QPainter *painter, const QWidget *widget = nullptr) const;
    void drawControl(QStyle::ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = nullptr) const;
    void drawPrimitive(QStyle::PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = nullptr) const;
    QRect subElementRect(QStyle::SubElement element, const QStyleOption *option, const QWidget *widget = nullptr) const;

    enum CombineBorder {
        Combine_None   = 0,
        Combine_Top    = 1,
        Combine_Left   = 2,
        Combine_Bottom = 4,
        Combine_Right  = 8
    };
    Q_DECLARE_FLAGS(CombineBorders, CombineBorder);

    static QPainterPath makeRoundedRect(QRectF base_rect, qreal rx, qreal ry, qreal width, CombineBorders cb);

private:
    QPalette palette;

    static QColor rgb(quint32 rgb);
};

Q_DECLARE_OPERATORS_FOR_FLAGS(QRockyStyle::CombineBorders);
