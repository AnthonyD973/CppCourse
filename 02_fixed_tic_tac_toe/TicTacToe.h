#pragma once

#include "QtWidgets/qwidget.h"

class TicTacToe : public QWidget
{
public:
	TicTacToe(QWidget* parent);
	~TicTacToe();

	void reset();
};

