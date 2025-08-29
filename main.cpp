
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
    palette.setColor(QPalette::Base, QColo(255, 255, 255));
    palette.setColor(QPalette::AlternateBase,QColor(233, 231, 227));
    palette.setColor(QPalette::ToolTipBase, Qt::white);
    palette.setColor(QPalette::ToolTipText, Qt::black);
    palette.setColor(QPalette::Text, Qt::black);
    palette.setColor(QPalette::Button, QColor(240, 240, 240));
    palette.setColor(QPalette::ButtonText,Qt::black);
    palette.setColor(QPalette::BrightText,Qt::red);
    palette.setColor(QPalette::Highlight,QColor(142, 45, 197).lighter());
    palette.setColor(QPalette::HighlightedText, Qt::black);


    MainWindow mainWindow;
    mainWindow.show();
    return a.exec();
}
