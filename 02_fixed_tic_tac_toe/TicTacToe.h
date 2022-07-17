#pragma once

#include "QtWidgets/qwidget.h"

#include "QtObjectToRowColumnMapping.h"

class TicTacToe : public QWidget
{
public:
    TicTacToe(QWidget* parent);
    ~TicTacToe();

    void reset();
    void buttonClicked();
    virtual void resizeEvent(QResizeEvent* event) override;

private:
    QtObjectToRowColumnMapping m_rcMappings;
};
