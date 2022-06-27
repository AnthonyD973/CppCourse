#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_helloworld.h"

class HelloWorld : public QMainWindow
{
    Q_OBJECT

public:
    HelloWorld(QWidget *parent = nullptr);
    ~HelloWorld();

private:
    Ui::HelloWorldClass ui;
};
