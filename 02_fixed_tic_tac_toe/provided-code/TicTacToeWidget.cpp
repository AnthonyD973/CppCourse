#include "TicTacToeWidget.h"

#include <iostream>

#include <qsignalmapper.h>
#include <qresizeevent>

#include "main_functions.h"

TicTacToeWidget::TicTacToeWidget(QWidget* parent) :
    SquareWidget(parent)
{
    // The buttons inside the "TicTacToe" Widget must be organized in a grid.
    m_layout = new QGridLayout(this);
    setupGame(this);
}

TicTacToeWidget::~TicTacToeWidget()
{}

/**
 * NOTE:
 *
 * This function with all its arguments made a line of code that was too
 * long, so I split the function's name and argument into multiple lines as
 * you can see. It's a good idea to break up long lines of code into
 * multiple smaller ones. One reason is that you can see everything without
 * having to scroll left and right all the time.
 */
void TicTacToeWidget::addButton(
    QPushButton* button,
    unsigned int row,
    unsigned int column
) {
    m_rcMappings.addMapping(button, row, column);
    m_layout->addWidget(button, row, column, 1, 1);
}

void TicTacToeWidget::buttonClicked() {
    // sender() is a Qt function that returns a pointer to the object that sent
    // the event that caused us to run this function.
    QObject* btn = sender();
    RowColumn rc = m_rcMappings.getMapping(btn);
    unsigned int row = rc.row;
    unsigned int column = rc.column;

    onButtonClicked(row, column);
}

void TicTacToeWidget::reset() {
    resetGame();
}
