#include "localserver.hpp"
#include <QLocalSocket>
#include <QTextStream>

LocalServer::LocalServer(QObject *parent)
    : QLocalServer(parent)
{
    connect(this, &LocalServer::newConnection, [&](){
        mSocket = this->nextPendingConnection();
    });
}

void LocalServer::send(const QString &message)
{
    if(mSocket)
    {
        QTextStream stream(mSocket);
        stream << message;
        mSocket->flush();
    }
}
