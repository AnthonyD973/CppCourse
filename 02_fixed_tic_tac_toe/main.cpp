#include "ttt_main_win.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TttMainWin w;
    w.show();
    return a.exec();
}
