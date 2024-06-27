#include "dialog.h"

#include <QApplication>

/*
Horizontal layout
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
