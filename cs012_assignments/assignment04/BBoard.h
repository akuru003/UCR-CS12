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
   User current_user;
   vector<Message> message_list;
   public:
   BBoard();
   BBoard(const string &ttl);
   void setup(const string &input_file);
   void login();
   void run();
   
};
#endif