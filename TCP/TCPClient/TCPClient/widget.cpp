#include "widget.hpp"
#include "ui_widget.h"
#include <QTcpSocket>
#include <QTextStream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    this->setWindowTitle("TcpClient");
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);

    connect(mSocket, &QTcpSocket::readyRead, [&](){
        QTextStream stream(mSocket);
        auto msg = stream.readAll();
        ui->listWidget->addItem(msg);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnConnect_clicked()
{
    mSocket->connectToHost(ui->txtHostAdress->text(), ui->spinnerPort->value());
}
