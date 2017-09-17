//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<7>/main.cpp 
/// @brief Assignment<7> for CS 12 <Winter & 2015>
///
/// @author <Abraham Kuruvila> [akuru003@ucr.edu]
/// @date <3/12/2015>
///
/// @par Enrollment Notes 
///     Lecture Section: <001>
/// @par
///     Lab Section: <001>
/// @par
///     TA: <Leo p Vu>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
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