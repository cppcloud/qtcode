#include "dialog.h"

#include <QApplication>

/*

Absoluate layouts are an absolute mistake to use.
They are the exact position on the container and do not scale.

 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
