#include "provided-code/TttMainWin.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TttMainWin w;
    w.show();
    return a.exec();
}
