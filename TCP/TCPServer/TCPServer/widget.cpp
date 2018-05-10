#include "widget.hpp"
#include "ui_widget.h"
#include "tcpserver.hpp"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("TcpServer");
    mServer = new TcpServer(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnSendMessage_clicked()
{
    mServer->send(ui->txtMessage->text());
}

void Widget::on_btnStartServer_clicked()
{
    if(mServer->isListening())
    {
        QMessageBox::critical(this, "Error",
                              "Server already started: " + mServer->errorString());
    }
    if(!mServer->listen(QHostAddress::Any, ui->spinnerPort->value()))
    {
        QMessageBox::critical(this, "Connection error",
                              "Error: " + mServer->errorString());
    }
    else
    {
        QMessageBox::information(this, "Success", "Connection successfull");
    }
}
