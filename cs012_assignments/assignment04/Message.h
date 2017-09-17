#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
using namespace std;
class Message
{
   private:
   string author;
   string subject;
   string body;
   public:
   Message();
   Message(const string &athr, const string &sbjct, const string &body);
   void display() const;
};
#endif