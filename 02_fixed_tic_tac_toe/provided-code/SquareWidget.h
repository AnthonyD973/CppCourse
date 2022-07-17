#pragma once

#include "qwidget.h"
#include "qresizeevent"

/**
 * Widgets that inherit this class will remain squares.
 */
class SquareWidget : public QWidget
{
public:
    explicit SquareWidget(QWidget* parent = nullptr);

    virtual void resizeEvent(QResizeEvent* event) override;
};

