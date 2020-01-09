#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include "AudioFile.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //класс что управляет потоком управления приложения GUI и основними настройками
    MainWindow w;
    w.show();

    return a.exec();
}
