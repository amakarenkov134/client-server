#ifndef MYSERVER_H
#define MYSERVER_H

#include <bitset>
#include <QTcpServer>
#include <QTcpSocket>


class MyServer: public QTcpServer
{
    Q_OBJECT
public:
    MyServer();
    ~MyServer();

    QTcpSocket* socket;
    QByteArray Data;
    std::string to_binary_string(unsigned int n);

public slots:
    void startServer();
    void incomingConnection(qintptr socketDescriptor);
    void sockReady();
    void sockDisc();
};

#endif // MYSERVER_H
