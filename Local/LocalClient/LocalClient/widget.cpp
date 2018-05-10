#include "widget.hpp"
#include "ui_widget.h"
#include <QLocalSocket>
#include <QTextStream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("LocalClient");
    mSocket = new QLocalSocket(this);
    connect(mSocket, &QLocalSocket::readyRead, [&](){
        QTextStream stream(mSocket);
        auto message = stream.readAll();
        ui->listWidget->addItem(message);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnConnect_clicked()
{
    mSocket->connectToServer(ui->txtServerName->text());
}

void Widget::on_btnQuit_clicked()
{
    this->close();
}
