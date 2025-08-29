
#include "mainwindow.h"

#include <QApplication>
#include <QPalette>
#include <QColor>


int main(int argc, char *argv[])
{
    QApplication app(int argc, char argv[]);

    app.setStyle("Fusion");

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(240, 240, 240));
    palette.setColor(QPalette::WindowText, Qt::black);
    MainWindow w;
    w.show();
    return a.exec();
}
