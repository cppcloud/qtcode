#include "dialog.h"

#include <QApplication>

//Grid layout

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
