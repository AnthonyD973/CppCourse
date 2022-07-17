#include "SquareWidget.h"

SquareWidget::SquareWidget(QWidget* parent) :
    QWidget(parent)
{}

void SquareWidget::resizeEvent(QResizeEvent* event)
{
    event->accept();

    // Ensure that the widget stays a square (try to remove
    // this code to see what would happen when you resize the window).
    const QSize current_size = size();
    const int min = std::min(current_size.width(), current_size.height());
    resize(min, min);
}
