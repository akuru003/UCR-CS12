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