#include "widget.hpp"
#include "ui_widget.h"
#include <QUdpSocket>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QUdpSocket(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnSend_clicked()
{
    auto datagram = ui->txtMessage->text().toLatin1();
    mSocket->writeDatagram(datagram, QHostAddress::Broadcast,
                           ui->spinnerPort->value());
}
