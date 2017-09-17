#ifndef USER_H
#define USER_H

#include <string>
using namespace std;
class User
{
   private:
   string username;
   string password;
   public:
   User();
   User(const string& uname, const string& pass);
   string get_username() const;
   bool check(const string &uname, const string &pass) const;
   void set_password(const string &newpass);
};
#endif