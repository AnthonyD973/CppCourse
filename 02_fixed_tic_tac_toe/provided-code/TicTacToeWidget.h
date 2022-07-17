#pragma once

#include "qpushbutton.h"
#include "qgridlayout.h"

#include "provided-code/QtObjectToRowColumnMapping.h"
#include "provided-code/SquareWidget.h"

/**
 * This only represents the tic-tac-toe part ("Widget") of the interface (like
 * adding buttons and making them do something). For the data of the
 * tic-tac-toe game, and for checking whether somebody has won, etc, we will
 * create a separate code file.
 */
class TicTacToeWidget : public SquareWidget
{
public:
    TicTacToeWidget(QWidget* parent = nullptr);
    ~TicTacToeWidget();

    /**
     * Function which is called whenever the "Game > Reset" action is clicked.
     */
    void reset();
    /**
     * Function which is needed by the widget to add buttons, and to know the
     * row/column that it is at.
     */
    void addButton(QPushButton* button, unsigned int row, unsigned int column);
    /**
     * Function which is called whenever one of the tic-tac-toe buttons is
     * clicked.
     */
    void buttonClicked();

private:
    QtObjectToRowColumnMapping m_rcMappings;
    QGridLayout* m_layout;
};
