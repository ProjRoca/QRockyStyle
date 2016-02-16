#include "../main_window.h"
#include <QLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) {
    setWindowTitle("QRockyStyle Demo");

    auto frame = new QWidget;
    auto layout = new QVBoxLayout;
    
    auto row0 = new QHBoxLayout;
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
