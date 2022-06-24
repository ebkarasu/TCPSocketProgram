#include "socket.h"

Socket::Socket(QObject *parent)
    : QObject{parent}
{
    socket = new QTcpSocket(this);
    QObject::connect(socket, &QTcpSocket::readyRead, this, &Socket::readData);
    QObject::connect(socket, &QTcpSocket::disconnected, this, &Socket::socketDisconnected);
}

Socket::~Socket(){
    delete this->socket;
}

int Socket::sendData(const std::string a){
    QString IP="127.0.0.1";
    int port=8765;
    socket->abort();
    socket->connectToHost(IP, port);
    if(socket->waitForConnected(3000)){
        error=0;
        }
    else{
        error=1;
    }
    QByteArray byteArray(a.c_str(), a.length());
    socket->write(byteArray);
    socket->flush();
    std::string stdstr(byteArray.constData(), byteArray.length());
    socket->disconnectFromHost();
    return error;
}

void Socket::readData(){
    QByteArray buffer;
        buffer = socket->readAll();
        if(!buffer.isEmpty())
        {
            QString str = "";
            str+=tr(buffer);
        }
}

void Socket::socketDisconnected(){
}
