#include <inttypes.h>

#include <algorithm>

#include <QtWidgets/QApplication>
#include <qpushbutton.h>

#include "provided-code/TttMainWin.h"
#include "provided-code/TicTacToeWidget.h"

#include "main_functions.h"

// The variables "tttData" and "turn" below are free for you
// to use or not. You will definitely need "tttWidget" though.

/**
 * The graphical interface element ("widget") that some code below adds all the
 * buttons of the tic-tac-toe to.
 */
TicTacToeWidget* tttWidget;
/**
 * Whose turn it is. Decide how to represent when it is "X"'s turn and when
 * it is "O"'s turn. For example, "X"'s turn could be when this variable is
 * equal to 0 and "O"'s turn when this variable is equal to 1.
 */
uint8_t tttTurn;
/**
 * The current state of the tic-tac-toe grid: who owns each cell. This is what
 * we call an array. An array is a squence of a certain number of times same
 * kind of value (in this case an array of 9 elements of 8-bit integers). You
 * can access an element of the array by doing "tttData[value]", where "value"
 * is called the "index" and can be a variable or a fixed value like 1. So
 * tttData[0] is the index 0 of tttData, tttData[6] is the element 6 of
 * tttData, and tttData[8] is the element 8 of tttData, which is also its last
 * element since tttData has 9 elements (indexes 0 to 8).
 *
 * You can write elements of the array like this:
 *
 * tttData[0] = 2; // Set element 0 of tttData to 2.
 *
 * You can use this array to represent who owns the cell. This means you have
 * to make these decisions:
 *
 * 1) Each element of this array would represent a cell of the tic-tac-toe
 * grid. But each element of this array is an 8-bit integer. That means you
 * have to decide how to use each such integer to represent who currently
 * owns that cell. For example, you could use the same values to represent
 * "X" and "O" as for representing the whose turn it is, plus another value
 * that represents that nobody owns that cell yet.
 *
 * 2) Decide how you want to represent rows and columns. For example, does
 * tttData[2] represent the rightmost cell of the first row or the bottommost
 * cell of the first column? I suggest going row by row (so that 0-2 are the
 * first row, 3-5 the second and 6-8 the third) because that's how it's usually
 * done, but do as you prefer.
 *
 * As always, since you're the one writing the code, you're the one taking
 * these decisions. Which ever ones you go with, as long as you stick with them
 * everywhere, and that you call the functions of the provided code correnctly,
 * your code will work correctly.
 */
uint8_t tttData[9];

/**
 * Function called whenever the "Game > Reset" action is selected, as well
 * as when the interface ("GUI") is initializing during the start of our
 * program.
 */
void resetGame() {
    // TODO Reset the state of the tic-tac-toe by calling tttWidget->reset()
    // (which resets the graphical stuff) and by resetting "tttTurn" and all
    // the elements of "tttData" back to the value you decided means that
    // nobody owns the cells of the grid.
}

/**
 * Function called whenever one of the buttons of the tic-tac-toe game is
 * clicked.
 */
void onButtonClicked(unsigned int row, unsigned int column) {
    // The value of "row" is 0 for the top row, 1 for the middle row and 2 for
    // the bottom row. Likewise, the value of "column" is 0 for the left
    // column, 1 for the middle column and 2 for the right column.


    // Start by experimenting calling this code:
    //
    // tttWidget->setButtonText(row, column, "X or O");
    //
    // Just try to replace "row" and "column" with values between 0 and 2,
    // restarting the program and clicking one of the buttons until you feel
    // confident you understand what that code does.

    // Then try to figure out how to determine the index of the element of
    // tttWidget from the "row" and "column" that you receive here. For
    // example, if "row" is 1 and "column" is 2, what is the index of "tttData"
    // that you must change?

    // Finally, and this is the hard part, you have to check each row, column,
    // as well as the two diagonals to see if they are all set to the same
    // value. If they are, that means that row, column, or diagonal completely
    // belongs to that player, which means that player won. So, in that case,
    // you have to do...
    //
    // tttWidget->setVictoryButton(row, column)
    //
    // ...for each row and column of the buttons that are part of the victory.
    //
    // E.g. if the middle column is a victory, then you must call:
    //
    // tttWidget->setVictoryButton(0, 1);
    // tttWidget->setVictoryButton(1, 1);
    // tttWidget->setVictoryButton(2, 1);
}

/**
 * Function called when the game's interface ("GUI") is being setup when the
 * program starts. It currently works just fine but is very difficult to read.
 * We will improve that.
 */
void setupGame(TicTacToeWidget* tttW) {
    tttWidget = tttW;
    // The buttons themselves have a minimum size but must take as much space
    // as possible, both horizontally and vertically.
    QSizePolicy btnSzP{
        QSizePolicy::Policy::MinimumExpanding,
        QSizePolicy::Policy::MinimumExpanding
    };

    // TODO We had to copy-paste all that code 9 times! This makes it hard to
    // change the code later. Plus we could easily make a mistake. Hmmm... How
    // can we do better?
    QPushButton* btn00 = new QPushButton(tttW);
    QPushButton* btn01 = new QPushButton(tttW);
    QPushButton* btn02 = new QPushButton(tttW);
    QPushButton* btn10 = new QPushButton(tttW);
    QPushButton* btn11 = new QPushButton(tttW);
    QPushButton* btn12 = new QPushButton(tttW);
    QPushButton* btn20 = new QPushButton(tttW);
    QPushButton* btn21 = new QPushButton(tttW);
    QPushButton* btn22 = new QPushButton(tttW);
    btn00->setSizePolicy(btnSzP);
    btn01->setSizePolicy(btnSzP);
    btn02->setSizePolicy(btnSzP);
    btn10->setSizePolicy(btnSzP);
    btn11->setSizePolicy(btnSzP);
    btn12->setSizePolicy(btnSzP);
    btn20->setSizePolicy(btnSzP);
    btn21->setSizePolicy(btnSzP);
    btn22->setSizePolicy(btnSzP);
    tttW->addButton(btn00, 0, 0);
    tttW->addButton(btn01, 0, 1);
    tttW->addButton(btn02, 0, 2);
    tttW->addButton(btn10, 1, 0);
    tttW->addButton(btn11, 1, 1);
    tttW->addButton(btn12, 1, 2);
    tttW->addButton(btn20, 2, 0);
    tttW->addButton(btn21, 2, 1);
    tttW->addButton(btn22, 2, 2);
    // These lines say that the "buttonClicked" of "TicTacToeWidget" must be
    // called whenever btnXY is clicked.
    //
    // These lines of code are quite long. Many people recommend not
    // writing lines longer than 80 characters. One reason is that you can see
    // everything without having to scroll left and right all the time.
    //
    // However, in this case if I broke these lines into multiple lines, then
    // it would be basically impossible to read the code. At least like this
    // the similar lines of code are all aligned, so we can spot errors a
    // little easier.
    //
    // Personally I almost never write lines of more than 80 characters, except
    // in cases like this to keep code aligned, but if you want to write
    // lines a little longer than that it's still okay.
    //
    // Remember: reading the code is more important than writing the code
    // because in the real world a line of code will be read many times before
    // somebody changes it. So always help others read your code (and help
    // future you who doesn't remember what the code does!) by formatting your
    // code well.
    //
    // But still, once we find a way to not have to repeat these 9 lines over,
    // we will be able to split this code into multiple lines since we will
    // only have one such line!
    tttW->connect(btn00, &QPushButton::clicked, tttW, &TicTacToeWidget::buttonClicked);
    tttW->connect(btn01, &QPushButton::clicked, tttW, &TicTacToeWidget::buttonClicked);
    tttW->connect(btn02, &QPushButton::clicked, tttW, &TicTacToeWidget::buttonClicked);
    tttW->connect(btn10, &QPushButton::clicked, tttW, &TicTacToeWidget::buttonClicked);
    tttW->connect(btn11, &QPushButton::clicked, tttW, &TicTacToeWidget::buttonClicked);
    tttW->connect(btn12, &QPushButton::clicked, tttW, &TicTacToeWidget::buttonClicked);
    tttW->connect(btn20, &QPushButton::clicked, tttW, &TicTacToeWidget::buttonClicked);
    tttW->connect(btn21, &QPushButton::clicked, tttW, &TicTacToeWidget::buttonClicked);
    tttW->connect(btn22, &QPushButton::clicked, tttW, &TicTacToeWidget::buttonClicked);
}

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    TttMainWin w;
    w.show();
    return a.exec();
}
