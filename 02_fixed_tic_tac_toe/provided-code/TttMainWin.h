#pragma once

#include <QtWidgets/QMainWindow>

#include "ui__fixed_tic_tac_toe.h"
#include "TicTacToeWidget.h"

class TttMainWin : public QMainWindow
{
    Q_OBJECT

public:
    TttMainWin(QWidget *parent = nullptr);
    ~TttMainWin();

    void resetGame();

private:
    Ui::_fixed_tic_tac_toeClass ui;
    TicTacToeWidget* m_ttt;
};
