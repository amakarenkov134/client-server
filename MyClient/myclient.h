#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>
#include <bitset>

QT_BEGIN_NAMESPACE
namespace Ui {
class MyClient;
}
QT_END_NAMESPACE

class MyClient : public QMainWindow
{
    Q_OBJECT

public:
    MyClient(QWidget *parent = nullptr);
    ~MyClient();

    QTcpSocket* socket;
    QByteArray m_data;


private slots:

    void onConnected();
    void sockReady();
    void sockDisc();
    void onConnectButtonClicked();
    void onDisconnecButtonClicked();
    void onSendButtonClicked();

private:
    Ui::MyClient *ui;
};
#endif // MYCLIENT_H
