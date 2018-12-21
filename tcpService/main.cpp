#include <QtCore/QCoreApplication>
#include <QtWidgets/QApplication>
#include <QTextCodec>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
