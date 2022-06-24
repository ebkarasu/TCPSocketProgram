#include "server.h"

Server::Server(QObject *parent)
    : QObject{parent}
{
    int port = 8765;

    server = new QTcpServer(this);

    QObject::connect(server, &QTcpServer::newConnection, this, &Server::newConnection);

    if(!server->listen(QHostAddress::Any, port)){
        qDebug() << "Server could not start.";
    }
    else{
        qDebug() << "Server started.";
    }
}

Server::~Server(){
    server->close();
    server->deleteLater();
}

void Server::newConnection(){
    socket = server->nextPendingConnection();
    QObject::connect(socket, &QTcpSocket::readyRead, this, &Server::readData);
    QObject::connect(socket, &QTcpSocket::disconnected, this, &Server::disconnected);
    qDebug() << "Client connected.";
}

void Server::readData(){
    QByteArray buffer;
    buffer = socket->readAll();
    if(!buffer.isEmpty())
    {
        QString str = "";
        str+=tr(buffer);
        info=str.toStdString();
    }
    int line1,line2,i=0,pos1=0,pos2=0,count=0,flag1=0,flag2=0;
    double money1,money2;
    string temp = "",linei,vectorstr;
    vector<string> v,t,y;
        t.clear();
        y.clear();

        for(int i=0;i<info.length();i++){
            if(info[i]==' '){
                v.push_back(temp);
                temp = "";
            }
            else{
                temp.push_back(info[i]);
            }

        }
        v.push_back(temp);

        line1=stoi(v[0]);
        money1=stod(v[1]);
    if(v.size()==4){
        line2=stoi(v[2]);
        money2=stod(v[3]);
    }

    if(v.size()==2){
        ifstream file("../TCP_Server/data.txt");
        if(file.is_open()){
            for(i=0;i<SIZE;i++){
                getline(file,vectorstr);
                t.push_back(vectorstr);
            }
            file.close();
            linei=t[line1-1];
        }
        for(i=0;i<linei.size();i++){
            if(linei[i] == ','){
                count++;
            }
            if(count==4 && flag1==0){
               pos1=i;
               flag1=1;
            }
            if(count==5 && flag2==0){
                pos2=i;
                flag2=1;
            }
        }
        linei.replace(1+pos1,pos2-pos1-1,to_string(stod(linei.substr(1+pos1,pos2-pos1-1))+money1));
        t[line1-1]=linei;

        ofstream file1("../TCP_Server/data.txt");
        if(file1.is_open()){
            for(i=0;i<SIZE-1;i++){
                file1 << t[i] << endl;
            }
            file1 << t[SIZE-1];
            file1.close();
        }
    }

    if(v.size()==4){
        string lineii;
        flag1=0;
        flag2=0;
        count=0;

        ifstream file("../TCP_Server/data.txt");
        if(file.is_open()){
            for(i=0;i<SIZE;i++){
                getline(file,vectorstr);
                t.push_back(vectorstr);
            }
            file.close();
            linei=t[line1-1];
            lineii=t[line2-1];
        }

        for(i=0;i<linei.size();i++){
            if(linei[i] == ','){
                count++;
            }
            if(count==4 && flag1==0){
               pos1=i;
               flag1=1;
            }
            if(count==5 && flag2==0){
                pos2=i;
                flag2=1;
            }
        }
        linei.replace(1+pos1,pos2-pos1-1,to_string(stod(linei.substr(1+pos1,pos2-pos1-1))-money1));
        t[line1-1]=linei;

        flag1=0;
        flag2=0;
        count=0;

        for(i=0;i<lineii.size();i++){
            if(lineii[i] == ','){
                count++;
            }
            if(count==4 && flag1==0){
               pos1=i;
               flag1=1;
            }
            if(count==5 && flag2==0){
                pos2=i;
                flag2=1;
            }
        }
        lineii.replace(1+pos1,pos2-pos1-1,to_string(stod(lineii.substr(1+pos1,pos2-pos1-1))+money2));
        t[line2-1]=lineii;

        ofstream file1("../TCP_Server/data.txt");
        if(file1.is_open()){
            for(i=0;i<SIZE-1;i++){
                file1 << t[i] << endl;
            }
            file1 << t[SIZE-1];
            file1.close();
        }
    }

    socket->flush();
}

void Server::disconnected(){
    socket->flush();
    socket->close();
}

std::string Server::getInfo(){
    return info;
}
