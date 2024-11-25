#include "myclient.h"
#include "ui_myclient.h"

MyClient::MyClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyClient)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));
    connect(socket, SIGNAL(connected()), this, SLOT(onConnected()));

    connect(ui->connectPushButton, QPushButton::clicked, this, &MyClient::onConnectButtonClicked);
    connect(ui->disconnecPushButton, QPushButton::clicked, this, &MyClient::onDisconnecButtonClicked);
    connect(ui->sendPushButton, QPushButton::clicked, this, &MyClient::onSendButtonClicked);
}

MyClient::~MyClient()
{
    delete ui;
}

void MyClient::onConnected()
{
    ui->connectionStatus->setText("Connect!");
}

void MyClient::sockDisc()
{
    socket->deleteLater();
}

void MyClient::sockReady()
{
    m_data = socket->readAll();

    ui->connectionStatus->setText(QString::fromStdString(m_data.toStdString()));

    qDebug()<<m_data.toStdString();
}

void MyClient::onConnectButtonClicked()
{
    socket->connectToHost("127.0.0.1", 5555, QIODevice::ReadWrite);
     //socket->connectToHost();
}


void MyClient::onDisconnecButtonClicked()
{
    ui->connectionStatus->setText("Disconnect!");
    socket->deleteLater();
}


void MyClient::onSendButtonClicked()
{
    if (ui->lineEdit->text() == ' ') {
        QMessageBox::information(this, "Ошибка", "Введите сообщение!");
        return;
    }

    QByteArray ba;

    ba.append(ui->lineEdit->text().toLocal8Bit());
    socket->write(ba);
}


