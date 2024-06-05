#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>

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
    QByteArray Data;

public slots:
    void sockReady();
    void sockDisc();

private slots:
    void on_connectPushButton_clicked();

private:
    Ui::MyClient *ui;
};
#endif // MYCLIENT_H
