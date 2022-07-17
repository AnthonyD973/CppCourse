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
     *
     * NOTE:
     *
     * This function with all its arguments made a line of code that was too
     * long, so I split the function's name and argument into multiple lines as
     * you can see. It's a good idea to break up long lines of code into
     * multiple smaller ones. One reason is that you can see everything without
     * having to scroll left and right all the time.
     *
     * Remember: reading the code is more important than writing the code
     * because in the real world a line of code will be read many times before
     * somebody changes it. So always help others read your code (and help future
     * you who doesn't remember what the code does!) by formatting your code well.
     *
     * Many people recommend not writing lines of more than 80 characters.
     * Personally I almost never write lines of more than 80 characters, but if you
     * want to write lines a bit longer than that it's still okay.
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
