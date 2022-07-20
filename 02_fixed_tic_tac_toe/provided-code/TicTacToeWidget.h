#pragma once

#include <vector>

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
     * Function which is needed by the widget to add buttons, and to know the
     * row/column that it is at.
     */
    void addButton(QPushButton* button, unsigned int row, unsigned int column);
    /**
     * Sets the text of the button at row "row" and column "column" to "text".
     *
     * Causes the program to stop with an error if either "row" or "column" is
     * greater than 2.
     */
    void setButtonText(unsigned int row, unsigned int column, const char* text);
    /**
     * Makes the button look different to indicate that that button is one of
     * the cells that made one of the players win.
     */
    void setVictoryButton(unsigned int row, unsigned int column);
    /**
     * Function which is called whenever one of the tic-tac-toe buttons is
     * clicked.
     */
    void buttonClicked();
    /**
     * Function which is called whenever the "Game > Reset" action is clicked.
     */
    void reset();

private:
    // These below are "private" functions. They cannot be called (except from
    // inside the TicTacToeWidget "class" itself).

    /**
     * Returns a "pointer" to the button at given row and column. Causes the
     * program to stop with an error if either "row" or "column" is greater
     * than 2.
     */
    QPushButton* getButton(unsigned int row, unsigned int column);

private:
    QtObjectToRowColumnMapping m_rcMappings;
    QGridLayout* m_layout;
    std::vector<QPushButton*> m_buttons;
};
