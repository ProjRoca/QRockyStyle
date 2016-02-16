#include "../main_window.h"
#include <QCheckBox>
#include <QComboBox>
#include <QDial>
#include <QDoubleSpinBox>
#include <QLayout>
#include <QLineEdit>
#include <QMenu>
#include <QMenuBar>
#include <QProgressBar>
#include <QPushButton>
#include <QRadioButton>
#include <QSlider>
#include <QToolBar>
#include <QToolButton>
#include <QRockyStyle.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) {
    setWindowTitle("QRockyStyle Demo");

    qreal em = QRockyStyle::em(this);

    auto menubar = new QMenuBar;
    auto menu_file = new QMenu("&File");
    menu_file->addAction("&New\tCtrl+N");
    menu_file->addSeparator();
    menu_file->addAction(u8"&Open\u2026\tCtrl+O");
    menu_file->addAction(u8"&Save\u2026\tCtrl+S");
    menu_file->addSeparator();
    menu_file->addAction("&Quit\tCtrl+Q");
    menubar->addMenu(menu_file);
    auto menu_help = new QMenu("&Help");
    menu_help->addAction(u8"&About\u2026");
    menubar->addMenu(menu_help);

    setMenuBar(menubar);

    auto frame = new QWidget;
    auto layout = new QVBoxLayout;
    layout->setMargin(qRound(em));
    layout->setSpacing(qRound(em));

    auto toolbar = new QHBoxLayout;
    toolbar->setSpacing(0);

    auto toolbtn0 = new QToolButton;
    toolbtn0->setIcon(QIcon::fromTheme("document-new"));
    toolbtn0->setMinimumSize(qRound(2*em), qRound(2*em));
    toolbar->addWidget(toolbtn0);

    auto toolbtn1 = new QToolButton;
    toolbtn1->setIcon(QIcon::fromTheme("document-open"));
    toolbtn1->setMinimumSize(qRound(2*em), qRound(2*em));
    toolbar->addWidget(toolbtn1);

    auto toolbtn2 = new QToolButton;
    toolbtn2->setIcon(QIcon::fromTheme("document-save"));
    toolbtn2->setMinimumSize(qRound(2*em), qRound(2*em));
    toolbar->addWidget(toolbtn2);

    toolbar->addStretch();
    layout->addLayout(toolbar);

    auto contents = new QVBoxLayout;
    contents->setSpacing(qRound(em));
    
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
    contents->addLayout(row0);

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
    contents->addLayout(row1);

    auto row2 = new QHBoxLayout;
    row2->setSpacing(qRound(em));
    row2->addWidget(new QSlider(Qt::Horizontal));
    {
        auto progbar = new QProgressBar;
        progbar->setValue(42);
        row2->addWidget(progbar);
    }
    contents->addLayout(row2);

    auto row3 = new QHBoxLayout;
    row3->addWidget(new QDial);
    auto row3col1 = new QVBoxLayout;
    row3col1->addWidget(new QCheckBox("Check"));
    row3col1->addWidget(new QRadioButton("Option 1"));
    row3col1->addWidget(new QRadioButton("Option 2"));
    row3->addLayout(row3col1);
    contents->addLayout(row3);

    contents->addStretch();

    auto row4 = new QHBoxLayout;
    row4->setSpacing(qRound(em));
    row4->addWidget(new QPushButton("OK"));
    row4->addWidget(new QPushButton("Cancel"));
    contents->addLayout(row4);

    layout->addLayout(contents);

    frame->setLayout(layout);
    setCentralWidget(frame);
    adjustSize();
}

MainWindow::~MainWindow() {
}
