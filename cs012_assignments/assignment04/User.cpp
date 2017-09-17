#include "User.h"
#include <string>
using namespace std;
User::User()
{
   username = "";
   password = "";
   return;
}
User::User(const string& uname, const string& pass)
{
   username = uname;
   password = pass; 
   return;
}
string User::get_username() const
{
   return username;
}
bool User::check(const string &uname, const string &pass) const
{
   if(uname == "")
   {
      return false;
   }
   else if((username == uname) && (password == pass))
   {
     return true;
   }
   return false;
}
void User::set_password(const string &newpass)
{
   password = newpass;
   return;
}