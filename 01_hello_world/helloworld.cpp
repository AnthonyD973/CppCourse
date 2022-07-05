#include "helloworld.h"

#include "QFileDialog.h"

HelloWorld::HelloWorld(QWidget *parent)
    : QMainWindow(parent)
    , m_cw(this)
    , m_openAct("&Open (doesn't actually do anything)", this)
{
    ui.setupUi(this);
    setCentralWidget(&m_cw);
    QMenu* helloMenu = menuBar()->addMenu("H&ello!!");
    auto doThing = [this]() {
        QString fileName = QFileDialog::getOpenFileName(this);
    };
    helloMenu->addAction(&m_openAct);
    connect(&m_openAct, &QAction::triggered, this, doThing);
}

HelloWorld::~HelloWorld()
{}
