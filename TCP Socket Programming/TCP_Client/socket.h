#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include <QString>
#include <QByteArray>
#include <QTcpSocket>
#include <QDebug>
#include <string>
#include <iostream>

class Socket : public QObject
{
    Q_OBJECT
public:
    explicit Socket(QObject *parent = nullptr);
    ~Socket();
    int sendData(const std::string a);
private:
    QTcpSocket *socket;
    int error;
private slots:
    void readData();
    void socketDisconnected();
signals:

};

#endif // SOCKET_H
