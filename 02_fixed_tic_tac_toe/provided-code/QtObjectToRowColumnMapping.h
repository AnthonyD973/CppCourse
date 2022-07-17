#pragma once

#include <vector>

#include "qobject.h"

#include "provided-code/RowColumn.h"

/**
 * You don't need to modify this code, but you can look at it if you want.
 *
 * This class holds "pointers" (which we will talk about later) to the buttons
 * of the TicTacToe game so that, when a button is clicked, we can retrieve the
 * row and column that correspond to this button.
 */
class QtObjectToRowColumnMapping
{
public:
    /**
     * Adds a mapping between the Qt object pointer and the given row and
     * column so that, from now on, getMapping() will return that mapping for
     * that pointer.
     */
    void addMapping(
        QObject* button,
        unsigned int row,
        unsigned int column
    );

    /**
     * Gets one of the mappings that were previously added with addMapping().
     *
     * Trying to call this with a pointer to a Qt Object that hasn't been added
     * with addMapping() will cause the program to stop with an error. Try it
     * if you want.
     */
    RowColumn getMapping(QObject* button);

private:
    std::map<QObject*, RowColumn> m_mappings;
};
