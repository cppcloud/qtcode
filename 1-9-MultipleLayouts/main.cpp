#include "dialog.h"

#include <QApplication>

/*
Multiple layouts
Nestled layouts
and Spacers
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
