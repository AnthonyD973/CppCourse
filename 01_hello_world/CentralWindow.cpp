#include "CentralWindow.h"

CentralWindow::CentralWindow(QWidget* parent)
	: QWidget(parent)
    , m_lay(this)
    , m_btn1{"Hello World1!"}
    , m_btn2{"Hello World2!"}
{
    setLayout(&m_lay);
    m_lay.addWidget(&m_btn1, 0, 0);
    m_lay.addWidget(&m_btn2, 0, 1, Qt::AlignBottom);
    m_lay.setSpacing(10);
}
