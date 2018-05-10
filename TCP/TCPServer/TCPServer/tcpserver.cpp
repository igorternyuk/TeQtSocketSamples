#include "tcpserver.hpp"
#include <QTcpSocket>
#include <QTextStream>

TcpServer::TcpServer(QObject *parent)
    : QTcpServer(parent)
{
    connect(this, &TcpServer::newConnection, [&](){
        mSocket = this->nextPendingConnection();
    });
}

void TcpServer::send(const QString &msg)
{
    if(mSocket)
    {
        QTextStream stream(mSocket);
        stream << msg;
        mSocket->flush();
    }
}
