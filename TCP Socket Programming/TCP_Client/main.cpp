#include <QCoreApplication>
#include <QDebug>
#include <QTcpSocket>
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include "socket.h"
#include "user.h"
#define SIZE 14

using namespace std;

string getElement(int element, int line, string directory){
    string str;
    int i,pos1=0,pos2=0;
    ifstream file(directory);
    for(i=1;i<line;i++){
        file.ignore(1000,'\n');
    }
    if (file.is_open()){
            getline(file,str);
            for(i=1;i<element;i++){
                pos1=str.find(",");
                str.erase(pos1,1);
            }
            pos2=str.find(",");
            str=str.substr(pos1,pos2-pos1);
    }
    file.close();
    return str;
}

void setUser(user *u,string a,string b,string c,string d,string e,string f,string g){
    u->setBank(a);
    u->setID(b);
    u->setPassword(c);
    u->setCardNumber(d);
    u->setBalance(stod(e));
    u->setName(f);
    u->setSurname(g);
}

string Lower(string a){
    int i=0;
    string b="";
    for(i=0;i<a.size();i++){
        b.push_back(tolower(a.at(i)));
    }
    return b;
}

int cardNumberPlace(string a){
    int i,j;
    for(i=1;i<SIZE;i++){
        if(a==getElement(4,i,"../TCP_Server/data.txt")){
            j=i;
        }
    }
    return j;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Socket s1;
    int i,j,k,PasswordCorrect=0,IDcorrect=0,opNum=0,choice=0,found=0;
    double money;
    string card,name,surname,username,password,allc,dir="../TCP_Server/data.txt";
    user u1,u2;

jump1:
    while(IDcorrect!=1 || PasswordCorrect!=1){
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        for(i=1;i<SIZE;i++){
            if(getElement(2,i,dir)==username){
                IDcorrect=1;
            }
            if(getElement(3,i,dir)==password){
                PasswordCorrect=1;
                j=i;
            }
        }

        if(IDcorrect==1 && PasswordCorrect==1){
            setUser(&u1,getElement(1,j,dir),getElement(2,j,dir),getElement(3,j,dir),getElement(4,j,dir),getElement(5,j,dir),getElement(6,j,dir),getElement(7,j,dir));
            cout << endl << "Welcome, " << u1.getName() << " " << u1.getSurname();
            cout << "   Your Balance: " << u1.getBalance();

            while(opNum!=1 && opNum!=2 && opNum!=3){
                cout << endl << "Please enter the operation you want to do:" << endl << "1. Send money" << endl;
                cout << "2. Withdraw money" << endl << "3. Deposit money" << endl;
                cin >> opNum;
                if(opNum==1){
                    cout << endl << "Enter the amount you want to send" << endl;
                    //cin >> money;
                    while (1) {
                        if (cin >> money){
                          // valid number
                          break;
                        }
                        else{
                          // not a valid number
                            cout << "Invalid Input! Please input a numerical value." << endl;
                            cin.clear();
                            while (cin.get() != '\n') ; // empty loop
                        }
                    }

jump2:
                    while(1){
                        if(money<=u1.getBalance()){
                            cout << endl << "Enter the card number of the receiver: ";
                            cin >> card;
                            u2.setCardNumber(card);
                            cout << endl << "Enter the name of the receiver: ";
                            cin >> name;
                            u2.setName(name);
                            cout << endl << "Enter the surname of the receiver: ";
                            cin >> surname;
                            u2.setSurname(surname);
                            for(i=1;i<SIZE;i++){
                                if(Lower(u2.getName()) == Lower(getElement(6,i,dir)) && Lower(u2.getSurname()) == Lower(getElement(7,i,dir)) && u2.getCardNumber() == getElement(4,i,dir)){
                                    found=1;
                                    j=i;
                                }

                            }
                            if(found){
                                u2.setBank(getElement(1,j,dir));
                                u2.setBalance(stod(getElement(5,j,dir)));

                                if(u1.getBank()==u2.getBank()){
                                    allc=to_string(cardNumberPlace(u1.getCardNumber())) + " " + to_string(money) + " " + to_string(cardNumberPlace(u2.getCardNumber()))+" "+to_string(money);
                                    if(s1.sendData(allc)){
                                        cout << "Server connection is failed... Please Try Again Later" << endl;
                                    }
                                    else{
                                        cout << "Money has successfully been sent." << endl;
                                    }
                                    break;
                                }
                                else{
                                    if(u1.getBank()=="Citigroup Inc."){
                                        allc=to_string(cardNumberPlace(u1.getCardNumber())) + " " + to_string(money) + " " + to_string(cardNumberPlace(u2.getCardNumber()))+" "+to_string(money*0.85);
                                        if(s1.sendData(allc)){
                                            cout << "Server connection is failed... Please Try Again Later" << endl;
                                        }
                                        else{
                                            cout << "Money has successfully been sent." << endl;
                                        }
                                        break;
                                    }
                                    else if(u1.getBank()=="Bank of America"){
                                        allc=to_string(cardNumberPlace(u1.getCardNumber())) + " " + to_string(money) + " " + to_string(cardNumberPlace(u2.getCardNumber()))+" "+to_string(money*0.9);
                                        if(s1.sendData(allc)){
                                            cout << "Server connection is failed... Please Try Again Later" << endl;
                                        }
                                        else{
                                            cout << "Money has successfully been sent." << endl;
                                        }
                                        break;
                                    }
                                    else if(u1.getBank()=="Truist Bank"){
                                        allc=to_string(cardNumberPlace(u1.getCardNumber())) + " " + to_string(money) + " " + to_string(cardNumberPlace(u2.getCardNumber()))+" "+to_string(money*0.95);
                                        if(s1.sendData(allc)){
                                            cout << "Server connection is failed... Please Try Again Later" << endl;
                                        }
                                        else{
                                            cout << "Money has successfully been sent." << endl;
                                        }
                                        break;
                                    }
                                    else if(u1.getBank()=="JPMorgan Chase & Co"){
                                        allc=to_string(cardNumberPlace(u1.getCardNumber())) + " " + to_string(money) + " " + to_string(cardNumberPlace(u2.getCardNumber()))+" "+to_string(money*0.975);
                                        if(s1.sendData(allc)){
                                            cout << "Server connection is failed... Please Try Again Later" << endl;
                                        }
                                        else{
                                            cout << "Money has successfully been sent." << endl;
                                        }
                                        break;
                                    }
                                    else{
                                        cout << "ERROR OCCCURED." << endl;
                                        break;
                                    }
                                }

                            }
                            else{
                                cout << "No data found. Please re-check your information." << endl << "1. Try Again" << endl << "2. Exit" << endl;
                                cin >> choice;
                                if(choice==1){
                                    goto jump2;
                                }
                                else if(choice==2){
                                    goto jump3;
                                }
                            }

                        }
                        else{
                            cout << "Not enough balance." << endl << endl;
                            IDcorrect = 0;
                            PasswordCorrect = 0;
                            opNum = 0;
                            goto jump1;
                        }
                    }

                    choice=0;
                    while(1){
                        cout << "Do you want to" << endl << "1. Perform another operation" << endl << "2. Exit" << endl;
                        cin >> choice;
                        if(choice==1){
                            IDcorrect = 0;
                            PasswordCorrect = 0;
                            opNum = 0;
                            goto jump1;
                        }
                        else if(choice==2){
                            goto jump3;
                        }
                        else{
                            cout << endl << "Please enter a valid number.";
                        }
                    }
                }
                if(opNum==2){
                    cout << endl << "Enter the amount you want to withdraw" << endl;
                    cin >> money;
                    if(u1.getBalance()>=money){
                        allc=to_string(cardNumberPlace(u1.getCardNumber())) + " " + "-" + to_string(money);
                        if(s1.sendData(allc)){
                            cout << "Server connection is failed... Please Try Again Later" << endl;
                        }
                        else{
                            cout << "Withdraw successful." << endl;
                        }
                    }
                    else{
                        cout << "Not enough balance." << endl << endl;
                        IDcorrect = 0;
                        PasswordCorrect = 0;
                        opNum = 0;
                        goto jump1;
                    }
                    choice=0;
                    while(1){
                        cout << "Do you want to" << endl << "1. Perform another operation" << endl << "2. Exit" << endl;
                        cin >> choice;
                        if(choice==1){
                            IDcorrect = 0;
                            PasswordCorrect = 0;
                            opNum = 0;
                            goto jump1;
                        }
                        else if(choice==2){
                            goto jump3;
                        }
                        else{
                            cout << endl << "Please enter a valid number.";
                        }
                    }
                }
                if(opNum==3){
                    cout << endl << "Enter the amount you want to deposit" << endl;
                    cin >> money;
                    allc=to_string(cardNumberPlace(u1.getCardNumber())) + " " + to_string(money);
                    if(s1.sendData(allc)){
                        cout << "Server connection is failed... Please Try Again Later" << endl;
                    }
                    else{
                        cout << "Deposit Successful." << endl;
                    }
                    choice=0;
                    while(1){
                        cout << "Do you want to" << endl << "1. Perform another operation" << endl << "2. Exit" << endl;
                        cin >> choice;
                        if(choice==1){
                            IDcorrect = 0;
                            PasswordCorrect = 0;
                            opNum = 0;
                            goto jump1;
                        }
                        else if(choice==2){
                            goto jump3;
                        }
                        else{
                            cout << endl << "Please enter a valid number.";
                        }
                    }
                }
            }
        }
        else{
            cout << "Wrong username or password, please try again." << endl;
        }
    }



jump3:
    return a.exec();
}
