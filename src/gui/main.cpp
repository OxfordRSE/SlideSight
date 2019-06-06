#include <QApplication>

#include "mainwindow.hpp"
#include "SightLib.hpp"
#include <assert.h> 

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    assert(sight::magic_function(3) == 8);

    return a.exec();
}
