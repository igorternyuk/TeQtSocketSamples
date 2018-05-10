#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>

class QTcpSocket;

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);

signals:

public slots:
    void send(const QString& msg);
private:
    QTcpSocket *mSocket;
};

#endif // TCPSERVER_H
