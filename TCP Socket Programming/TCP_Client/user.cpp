#include "user.h"

user::user(){}

void user::setBank(string b){
    Bank=b;
}
void user::setID(string i){
    ID=i;
}
void user::setPassword(string p){
    Password=p;
}
void user::setCardNumber(string c){
    CardNumber=c;
}
void user::setBalance(double b){
    Balance=b;
}
void user::setName(string n){
    Name=n;
}
void user::setSurname(string s){
    Surname=s;
}
string user::getBank(void){
    return Bank;
}
string user::getID(void){
    return ID;
}
string user::getPassword(void){
    return Password;
}
string user::getCardNumber(void){
    return CardNumber;
}
double user::getBalance(void){
    return Balance;
}
string user::getName(void){
    return Name;
}
string user::getSurname(void){
    return Surname;
}
