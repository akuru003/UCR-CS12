#include "Message.h"
#include <iostream>
using namespace std;

Message::Message()
: author(""), subject(""), body("")
{
   
}
Message::Message(const string &athr, const string &sbjct, const string &body)
: author(athr), subject(sbjct), body(body)
{
   
}
void Message::display() const
{
   cout << subject << endl;
   cout << "from " << author << ": " << body << endl;
} 