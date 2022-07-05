#include "CentralWindow.h"

CentralWindow::CentralWindow(QWidget* parent)
	: QWidget(parent)
    , m_lay(this)
    , m_btn1{"Hello World1!"}
    , m_btn2{"Hello World2!"}
{
    m_btn1.setToolTip("This button doesn't actually do anything");
    m_btn2.setToolTip("This button doesn't actually do anything either");
    setLayout(&m_lay);
    m_lay.addWidget(&m_btn1, 0, 0);
    m_lay.addWidget(&m_btn2, 0, 1);
    m_lay.setSpacing(10);
}
