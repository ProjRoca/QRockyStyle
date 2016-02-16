#include "../main_window.h"
#include <QCheckBox>
#include <QComboBox>
#include <QDial>
#include <QDoubleSpinBox>
#include <QLayout>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QRadioButton>
#include <QSlider>
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
    row0->addWidget(new QLineEdit("Input box"));
    {
        auto combo = new QComboBox;
        combo->setEditable(true);
        combo->addItem("44100");
        combo->addItem("48000");
        combo->addItem("96000");
        combo->addItem("192000");
        row0->addWidget(combo);
    }
    layout->addItem(row0);

    auto row1 = new QHBoxLayout;
    row1->setSpacing(qRound(em));
    row1->addWidget(new QDoubleSpinBox);
    {
        auto combo = new QComboBox;
        combo->addItem("44100");
        combo->addItem("48000");
        combo->addItem("96000");
        combo->addItem("192000");
        row1->addWidget(combo);
    }
    layout->addItem(row1);

    auto row2 = new QHBoxLayout;
    row2->setSpacing(qRound(em));
    row2->addWidget(new QSlider(Qt::Horizontal));
    {
        auto progbar = new QProgressBar;
        progbar->setValue(42);
        row2->addWidget(progbar);
    }
    layout->addItem(row2);

    auto row3 = new QHBoxLayout;
    row3->addWidget(new QDial);
    auto row3col1 = new QVBoxLayout;
    row3col1->addWidget(new QCheckBox("Check"));
    row3col1->addWidget(new QRadioButton("Option 1"));
    row3col1->addWidget(new QRadioButton("Option 2"));
    row3->addItem(row3col1);
    layout->addItem(row3);

    auto row4 = new QHBoxLayout;
    row4->setSpacing(qRound(em));
    row4->addWidget(new QPushButton("OK"));
    row4->addWidget(new QPushButton("Cancel"));
    layout->addItem(row4);

    frame->setLayout(layout);
    setCentralWidget(frame);
    adjustSize();
}

MainWindow::~MainWindow() {
}
