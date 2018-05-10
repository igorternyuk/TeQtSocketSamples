#include "widget.hpp"
#include "ui_widget.h"
#include "localserver.hpp"
#include <QTextStream>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("LocalServer");
    this->setFixedSize(this->size());
    mLocalServer = new LocalServer(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnStartServer_clicked()
{
    if(mLocalServer->isListening())
    {
        QMessageBox::critical(this, "Error", "Connection already exists");
        return;
    }

    auto serverName = ui->txtServerName->text();

    if(!mLocalServer->listen(serverName))
    {
        QMessageBox::critical(this, "Connection error",
                              "Could not connect to server: " + serverName + " "
                              + mLocalServer->errorString());
    }
    else
    {
        QMessageBox::information(this, "Connection information",
                                 "Connection to the server " + serverName
                                 + " was succesfully established");
    }

}

void Widget::on_btnSendMessage_clicked()
{
    mLocalServer->send(ui->txtMessage->text());
}

void Widget::on_btnQuit_clicked()
{
    this->close();
}
