#include "mainwindow.h"
#include <QIcon>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setWindowTitle("FractIOns");
    a.setWindowIcon(QIcon(":/images/math.png"));


    w.show();
    return a.exec();
}
