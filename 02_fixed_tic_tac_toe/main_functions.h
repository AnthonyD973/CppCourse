#pragma once

class TicTacToeWidget;

// This below says: "Functions setupGame, resetGame and onButtonClicked
// exist somewhere in some .cpp file."
//
// Doing this is needed so that other files can know that these functions
// exist even if they can't see them. You will write and modify the code of
// these functions below. They are in main.cpp.
//
// You do not need to change this file.

void setupGame(TicTacToeWidget* tttWidget);
void resetGame();
void onButtonClicked(unsigned int row, unsigned int column);
