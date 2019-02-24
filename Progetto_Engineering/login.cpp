#include "login.h"

Login::Login(const string & user, const string & pass):Username(user),Password(pass){}

Login::~Login(){}

bool Login::Connection(const string & user, const string & pass) const{

    return user=="admin" && pass=="admin";
}
