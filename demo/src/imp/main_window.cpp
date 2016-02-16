#include "../main_window.h"
#include <QLayout>
#include <QPushButton>
#include <QRockyStyle.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) {
    setWindowTitle("QRockyStyle Demo");

    qreal em = QRockyStyle::em(this);

    auto frame = new QWidget;
    auto layout = new QVBoxLayout;
    layout->setMargin(qRound(em));
    layout->setSpacing(qRound(em));
    
    auto row0 = new QHBoxLayout;
    row0->setSpacing(qRound(em));
    row0->addWidget(new QPushButton("OK"));
    row0->addWidget(new QPushButton("Cancel"));
    layout->addItem(row0);

    frame->setLayout(layout);
    frame->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    setCentralWidget(frame);
    adjustSize();
}

MainWindow::~MainWindow() {
}
