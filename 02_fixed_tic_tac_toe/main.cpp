#include <QtWidgets/QApplication>
#include <qpushbutton.h>

#include "provided-code/TttMainWin.h"
#include "provided-code/TicTacToeWidget.h"

#include "main_functions.h"

/**
 * Function called when the game's interface ("GUI") is being setup when the
 * program starts. It currently works just fine but is very difficult to read.
 */
void setupGame(TicTacToeWidget* tttWidget) {
    // The buttons themselves have a minimum size but must take as much space
    // as possible, both horizontally and vertically.
    QSizePolicy btnSzP{
        QSizePolicy::Policy::MinimumExpanding,
        QSizePolicy::Policy::MinimumExpanding
    };

    // TODO We had to copy-paste that code 9 times! This makes it hard to
    // change the code later. Plus we could easily make a mistake. Hmmm... How
    // can we do better?
    QPushButton* btn00 = new QPushButton(tttWidget);
    QPushButton* btn01 = new QPushButton(tttWidget);
    QPushButton* btn02 = new QPushButton(tttWidget);
    QPushButton* btn10 = new QPushButton(tttWidget);
    QPushButton* btn11 = new QPushButton(tttWidget);
    QPushButton* btn12 = new QPushButton(tttWidget);
    QPushButton* btn20 = new QPushButton(tttWidget);
    QPushButton* btn21 = new QPushButton(tttWidget);
    QPushButton* btn22 = new QPushButton(tttWidget);
    btn00->setSizePolicy(btnSzP);
    btn01->setSizePolicy(btnSzP);
    btn02->setSizePolicy(btnSzP);
    btn10->setSizePolicy(btnSzP);
    btn11->setSizePolicy(btnSzP);
    btn12->setSizePolicy(btnSzP);
    btn20->setSizePolicy(btnSzP);
    btn21->setSizePolicy(btnSzP);
    btn22->setSizePolicy(btnSzP);
    tttWidget->addButton(btn00, 0, 0);
    tttWidget->addButton(btn01, 0, 1);
    tttWidget->addButton(btn02, 0, 2);
    tttWidget->addButton(btn10, 1, 0);
    tttWidget->addButton(btn11, 1, 1);
    tttWidget->addButton(btn12, 1, 2);
    tttWidget->addButton(btn20, 2, 0);
    tttWidget->addButton(btn21, 2, 1);
    tttWidget->addButton(btn22, 2, 2);
    // These lines of code are quite long. Many people recommend not
    // writing lines longer than 80 characters. One reason is that you can see
    // everything without having to scroll left and right all the time.
    //
    // However, in this case if I broke these lines into multiple lines, then
    // it would be basically impossible to read the code. At least like this
    // the code is aligned, and we can spot errors a little easier.
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
    tttWidget->connect(btn00, &QPushButton::clicked, tttWidget, &TicTacToeWidget::buttonClicked);
    tttWidget->connect(btn01, &QPushButton::clicked, tttWidget, &TicTacToeWidget::buttonClicked);
    tttWidget->connect(btn02, &QPushButton::clicked, tttWidget, &TicTacToeWidget::buttonClicked);
    tttWidget->connect(btn10, &QPushButton::clicked, tttWidget, &TicTacToeWidget::buttonClicked);
    tttWidget->connect(btn11, &QPushButton::clicked, tttWidget, &TicTacToeWidget::buttonClicked);
    tttWidget->connect(btn12, &QPushButton::clicked, tttWidget, &TicTacToeWidget::buttonClicked);
    tttWidget->connect(btn20, &QPushButton::clicked, tttWidget, &TicTacToeWidget::buttonClicked);
    tttWidget->connect(btn21, &QPushButton::clicked, tttWidget, &TicTacToeWidget::buttonClicked);
    tttWidget->connect(btn22, &QPushButton::clicked, tttWidget, &TicTacToeWidget::buttonClicked);
}

void resetGame() {
    // Function called whenever the "Game > Reset" action is selected.
}

void onButtonClicked(unsigned int row, unsigned int column) {
    // Function called whenever one of the buttons of the tic-tac-toe game is
    // clicked.

    // The value of "row" is 0 for the top row, 1 for the middle row and 2 for
    // the bottom row. Likewise, the value of "column" is 0 for the left
    // column, 1 for the middle column and 2 for the right column.
}

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    TttMainWin w;
    w.show();
    return a.exec();
}
