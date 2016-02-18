#include <QApplication>
#include <QRockyStyle.h>
#include "../main_window.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    app.setStyle(new QRockyStyle);

    MainWindow w;
    w.show();

    return app.exec();
}
