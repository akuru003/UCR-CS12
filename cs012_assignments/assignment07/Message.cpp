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
#include "Message.h"
#include <iostream>
using namespace std;

Message::Message()
: author(""), subject(""), body(""), id(0)
{}
Message::Message(const string &athr, const string &sbjct, const string &body, unsigned id)
: author(athr), subject(sbjct), body(body), id(id)
{}
Message::~Message()
{}
void Message::print(unsigned indentation) const
{
   string Mess = body;
   int size = Mess.size() - 1;
   string indent = "";
   if(is_reply())
   {
      cout << endl;
   }
   for(unsigned i = 0; i < indentation; i++) // adds spaces for indent
   {                                         // recursively...
      indent += "  ";
   }
   cout << indent << "Message #" << this->get_id() << ": " << this->get_subject();
   cout << endl;
   cout << indent << "from " << author << ": ";
   for(int i = 0; i < size; i++)
   {
      if(Mess.at(i) == '\n')
      {
         Mess.insert(i + 1, indent);
      }
   }
   cout << Mess << endl;
   if(child_list.size() >= 1)
   {
      for(unsigned i = 0; i < child_list.size(); i++)
      {
         child_list.at(i)->print(indentation + 1);
      }
   }
}
const string & Message::get_subject() const
{
    return subject;
}
unsigned Message::get_id() const
{
    return id;
}
void Message::add_child(Message *child)
{
    child_list.push_back(child);
}