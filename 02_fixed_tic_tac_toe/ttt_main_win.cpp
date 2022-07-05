#include "ttt_main_win.h"

TttMainWin::TttMainWin(QWidget *parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);
    m_ttt = new TicTacToe(this);
    setCentralWidget(m_ttt);

    // Add a "Game" menu.
    QMenu* gameMenu = menuBar()->addMenu("Game");
    // Create a "Reset" action.
    QAction* gameResetAct = new QAction("Reset", this);
    // Add the "Reset" action to the "Game" menu.
    gameMenu->addAction(gameResetAct);
    // Whenever the "Reset" action is triggered, call the "resetGame" function
    // below on "this" main window.
    connect(gameResetAct, &QAction::triggered, this, &TttMainWin::resetGame);
}

TttMainWin::~TttMainWin()
{}

void TttMainWin::resetGame() {
    m_ttt->reset();
}
