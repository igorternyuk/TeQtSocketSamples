#include "widget.hpp"
#include "ui_widget.h"
#include <QUdpSocket>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QUdpSocket(this);
    connect(mSocket, &QUdpSocket::readyRead, [&](){
        if(mSocket->hasPendingDatagrams())
        {
            QByteArray datagram;
            datagram.resize(mSocket->pendingDatagramSize());
            mSocket->readDatagram(datagram.data(), datagram.size());
            ui->listWidget->addItem(QString::fromStdString(datagram.toStdString()));
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    mSocket->bind(ui->spinnerPort->value(), QUdpSocket::ShareAddress);
}
