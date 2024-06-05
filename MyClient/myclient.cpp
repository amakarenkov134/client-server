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

        qDebug()<<Data.toStdString();

}

void MyClient::on_connectPushButton_clicked()
{
    socket->connectToHost("127.0.0.1", 5555, QIODevice::WriteOnly);
     //socket->connectToHost();
}


void MyClient::on_disconnecPushButton_clicked()
{
    ui->connectionStatus->setText("Disconnect!");
    socket->deleteLater();
}


void MyClient::on_sendPushButton_clicked()
{
    std::bitset<8> bits;

    bits[7] = 1;

    bits[6] = 0;

    bits[5] = 1;



    uint8_t localData = bits.to_ulong();

    // const char *c = reinterpret_cast<const char *>(localData);

    QByteArray ba;

    //ba.resize(1);
    ba.append(localData);

    //const char *hui = reinterpret_cast<const *char>

    socket->write(ba);
}


