#ifndef USER_H
#define USER_H
#include<string>

using namespace std;

class user
{
public:
    user();
    void setBank(string b);
    void setID(string i);
    void setPassword(string p);
    void setCardNumber(string c);
    void setBalance(double b);
    void setName(string n);
    void setSurname(string s);
    string getBank(void);
    string getID(void);
    string getPassword(void);
    string getCardNumber(void);
    double getBalance(void);
    string getName(void);
    string getSurname(void);
private:
    string Bank;
    string ID;
    string Password;
    string CardNumber;
    double Balance;
    string Name;
    string Surname;
};

#endif // USER_H
