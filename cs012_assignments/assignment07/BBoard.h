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
#ifndef BBOARD_H
#define BBOARD_H
#include "Message.h"
#include "User.h"
#include <string>
#include <vector> 
class BBoard
{
   private:
   string title;
   vector<User> user_list;
   const User* current_user;
   vector<Message  *> message_list;
   public:
   BBoard();
   BBoard(const string &ttl);
   ~BBoard();
   bool load_users(const string &userfile);
   bool load_messages(const string& datafile);
   bool save_messages(const string& datefile);
   void login();
   void run();
   private:
   void add_topic();
   void add_reply();
};
#endif