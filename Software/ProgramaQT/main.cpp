#include "generador_de_pulsos.h"
#include <QApplication>
#include <QThread>
#include "worker.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Generador_de_pulsos w;
    w.show();


    return a.exec();
}
