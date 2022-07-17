#include "TicTacToeWidget.h"

#include <iostream>

#include <qgridlayout.h>
#include <qpushbutton.h>
#include <qsignalmapper.h>
#include <qresizeevent>

TicTacToeWidget::TicTacToeWidget(QWidget* parent) :
    SquareWidget(parent)
{
    // The buttons inside the "TicTacToe" Widget must be organized in a grid.
    QGridLayout* layout = new QGridLayout(this);

    // The buttons themselves have a minimum size but must take as much space
    // as possible, both horizontally and vertically.
    QSizePolicy btnSzP{
        QSizePolicy::Policy::MinimumExpanding,
        QSizePolicy::Policy::MinimumExpanding
    };

    // TODO We had to copy-paste that code 9 times! This makes it hard to
    // change the code later. Plus we could easily make a mistake. Hmmm... How
    // can we do better?
    QPushButton* btn00 = new QPushButton(this);
    QPushButton* btn01 = new QPushButton(this);
    QPushButton* btn02 = new QPushButton(this);
    QPushButton* btn10 = new QPushButton(this);
    QPushButton* btn11 = new QPushButton(this);
    QPushButton* btn12 = new QPushButton(this);
    QPushButton* btn20 = new QPushButton(this);
    QPushButton* btn21 = new QPushButton(this);
    QPushButton* btn22 = new QPushButton(this);
    btn00->setSizePolicy(btnSzP);
    btn01->setSizePolicy(btnSzP);
    btn02->setSizePolicy(btnSzP);
    btn10->setSizePolicy(btnSzP);
    btn11->setSizePolicy(btnSzP);
    btn12->setSizePolicy(btnSzP);
    btn20->setSizePolicy(btnSzP);
    btn21->setSizePolicy(btnSzP);
    btn22->setSizePolicy(btnSzP);
    layout->addWidget(btn00, 0, 1, 1, 1);
    layout->addWidget(btn01, 0, 2, 1, 1);
    layout->addWidget(btn02, 0, 3, 1, 1);
    layout->addWidget(btn10, 1, 1, 1, 1);
    layout->addWidget(btn11, 1, 2, 1, 1);
    layout->addWidget(btn12, 1, 3, 1, 1);
    layout->addWidget(btn20, 2, 1, 1, 1);
    layout->addWidget(btn21, 2, 2, 1, 1);
    layout->addWidget(btn22, 2, 3, 1, 1);
    m_rcMappings.addMapping(btn00, 0, 0);
    m_rcMappings.addMapping(btn01, 0, 1);
    m_rcMappings.addMapping(btn02, 0, 2);
    m_rcMappings.addMapping(btn10, 1, 0);
    m_rcMappings.addMapping(btn11, 1, 1);
    m_rcMappings.addMapping(btn12, 1, 2);
    m_rcMappings.addMapping(btn20, 2, 0);
    m_rcMappings.addMapping(btn21, 2, 1);
    m_rcMappings.addMapping(btn22, 2, 2);
    connect(btn00, &QPushButton::clicked, this, &TicTacToeWidget::buttonClicked);
    connect(btn01, &QPushButton::clicked, this, &TicTacToeWidget::buttonClicked);
    connect(btn02, &QPushButton::clicked, this, &TicTacToeWidget::buttonClicked);
    connect(btn10, &QPushButton::clicked, this, &TicTacToeWidget::buttonClicked);
    connect(btn11, &QPushButton::clicked, this, &TicTacToeWidget::buttonClicked);
    connect(btn12, &QPushButton::clicked, this, &TicTacToeWidget::buttonClicked);
    connect(btn20, &QPushButton::clicked, this, &TicTacToeWidget::buttonClicked);
    connect(btn21, &QPushButton::clicked, this, &TicTacToeWidget::buttonClicked);
    connect(btn22, &QPushButton::clicked, this, &TicTacToeWidget::buttonClicked);
}

TicTacToeWidget::~TicTacToeWidget()
{}

void TicTacToeWidget::buttonClicked() {
    // sender() is a Qt function that returns a pointer to the object that sent
    // the event that caused us to run this function.
    QObject* btn = sender();
    RowColumn rc = m_rcMappings.getMapping(btn);
    unsigned int row = rc.row;
    unsigned int column = rc.column;

    // TODO After creating your own code that represents the "state" of the
    // game (such as if the game is finished, where the "X" and "O" are), ask
    // that code to update the state knowing that we just clicked the button at
    // "row" and "column".
    std::cout << "(" << row << "," << column << ")\n";
}

void TicTacToeWidget::reset() {
    // TODO After creating your own code that represents the "state" of the
    // game, reset that state here.
}
