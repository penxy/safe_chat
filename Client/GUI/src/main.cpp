#include <QApplication>
#include "widget_login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WidgetLogin w;
    w.show();
    return a.exec();
}
