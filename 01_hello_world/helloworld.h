#pragma once

#include <QtWidgets/QMainWindow>
#include "QAction.h"

#include "ui_helloworld.h"
#include "CentralWindow.h"

class HelloWorld : public QMainWindow
{
    Q_OBJECT

public:
    HelloWorld(QWidget *parent = nullptr);
    ~HelloWorld();

private:
    Ui::HelloWorldClass ui;
    CentralWindow m_cw;
    QAction m_openAct;
};
