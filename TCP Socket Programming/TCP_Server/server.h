#ifndef SERVER_H
#define SERVER_H
#define SIZE 13

#include <QObject>
#include <QString>
#include <QByteArray>
#include <QTcpSocket>
#include <QTcpServer>
#include <QHostAddress>
#include <QDebug>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();
    std::string getInfo();

signals:
public slots:
    void readData();
    void newConnection();
    void disconnected();
private:
    QTcpServer *server;
    QTcpSocket *socket;
    std::string info;

};

#endif // SERVER_H
