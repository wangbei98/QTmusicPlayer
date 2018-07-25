#include "ourplayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ourplayer w(0);
    w.show();

    return a.exec();
}
