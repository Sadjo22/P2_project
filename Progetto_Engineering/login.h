#ifndef LOGIN_H
#define LOGIN_H
#include<string>
#include<iostream>
using namespace std;

class Login
{
public:
    Login(const string &, const string &);
    ~Login();
    bool Connection(const string &, const string &)const;

private:
    string Username;
    string Password;
};

#endif // LOGIN_H
