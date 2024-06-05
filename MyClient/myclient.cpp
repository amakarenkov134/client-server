#include "myclient.h"
#include "ui_myclient.h"

MyClient::MyClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyClient)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);
    connect(socket,SIGNAL(readyRead()),this,SLOT(sockReady()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(sockDisc()));
}

MyClient::~MyClient()
{
    delete ui;
}

void MyClient::sockDisc()
{
    socket->deleteLater();
}

void MyClient::sockReady()
{
        Data = socket->readAll();
        qDebug()<<Data;
        ui->connectionStatus->setText(Data);
}

void MyClient::on_connectPushButton_clicked()
{
     socket->connectToHost("127.0.0.1", 5555);
}

