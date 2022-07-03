#pragma once

#include "QtWidgets/QWidget.h"
#include <QtWidgets/QPushButton.h>
#include <QtWidgets/qgridlayout.h>

class CentralWindow : public QWidget
{
public:
	explicit CentralWindow(QWidget* parent);

private:
    QGridLayout m_lay;
    QPushButton m_btn1;
    QPushButton m_btn2;
};

