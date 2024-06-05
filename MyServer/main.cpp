#include <QCoreApplication>
#include "MyServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyServer Server;
    Server.startServer();

    return a.exec();
}
