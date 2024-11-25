#include "MyServer.h"

MyServer::MyServer(){}

MyServer::~MyServer(){}

std::string MyServer::to_binary_string(unsigned int n)
{
    std::string buffer; // символы ответа в обратном порядке
    // выделим память заранее по максимуму
    buffer.reserve(std::numeric_limits<unsigned int>::digits);
    do
    {
        buffer += char('0' + n % 2); // добавляем в конец
        n = n / 2;
    } while (n > 0);
    return std::string(buffer.crbegin(), buffer.crend());
}

void MyServer::startServer()
{
    if (this->listen(QHostAddress::Any, 5555))
    {
        qDebug()<<"Listening";
    }
    else
    {
        qDebug()<<"Not listening";
    }
}

void MyServer::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket,SIGNAL(readyRead()),this,SLOT(sockReady()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(sockDisc()));

    qDebug()<<socketDescriptor<<" Client connected";


    qDebug()<<"Send client connect status - YES";
}



void MyServer::sockReady()
{
    data = socket->readAll();

    socket->write(QString::fromStdString("Server:" + data.toStdString()).toLocal8Bit());
    data.clear();
}

void MyServer::sockDisc()
{
    qDebug()<<"Disconnect";
    socket->deleteLater();
}
