#include "TicTacToeWidget.h"

#include <iostream>

#include <qsignalmapper.h>
#include <qresizeevent>

#include "main_functions.h"

/**
 * The number of rows (and of columnd) of the tic-tac-toe.
 */
const unsigned int GRID_SIZE = 3;

TicTacToeWidget::TicTacToeWidget(QWidget* parent) :
    SquareWidget(parent)
{
    // The buttons inside the "TicTacToe" Widget must be organized in a grid.
    m_layout = new QGridLayout(this);
    setupGame(this);
    resetGame();
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
    m_buttons.push_back(button);
    m_layout->addWidget(button, row, column, 1, 1);
}

void TicTacToeWidget::buttonClicked() {
    // sender() is a Qt function that returns a pointer to the object that sent
    // the event that caused us to run this function.
    QObject* obj = sender();
    RowColumn rc = m_rcMappings.getMapping(obj);
    unsigned int row = rc.row;
    unsigned int column = rc.column;

    onButtonClicked(row, column);

    // Disable the button
    getButton(row, column)->setEnabled(false);
}

void TicTacToeWidget::reset() {
    for (QPushButton* btn : m_buttons) {
        // Clear the text of the button
        btn->setText("");
        // Enable all the buttons
        btn->setEnabled(true);
    }

    resetGame();
}

void TicTacToeWidget::setButtonText(
    unsigned int row,
    unsigned int column,
    const char* text
) {
    getButton(row, column)->setText(text);
}

void TicTacToeWidget::setVictoryButton(unsigned int row, unsigned int column) {
    // Disable all the buttons
    for (QPushButton* button : m_buttons) {
        button->setEnabled(false);
    }

    QPushButton* button = getButton(row, column);
    // #70FF70 is kind of a whiteish green (0x70=112 for red,
    // 0xFF=255 for green and 0x70=112 for blue):
    // https://en.wikipedia.org/wiki/Web_colors
    button->setStyleSheet("background-color: #70ff70");
}

QPushButton* TicTacToeWidget::getButton(unsigned int row, unsigned int column) {
    if (row > GRID_SIZE || column > GRID_SIZE) {
        // To cause the program to crash right away if "row" or "column"
        // are wrong, rather than waiting to get some stranger problems.
        throw std::runtime_error{ "Bad row or column number" };
    }
    // The number of the button inside "m_buttons"
    size_t button_number = row * GRID_SIZE + column;
    // Return the pointer to button to whoever requested it.
    return m_buttons.at(button_number);
}
