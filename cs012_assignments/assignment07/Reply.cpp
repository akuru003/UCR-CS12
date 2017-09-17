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
#include "Reply.h"
#include "Message.h"
#include <iostream>
#include <sstream>
using namespace std;

Reply::Reply()
 : Message()
{}
Reply::Reply(const string &athr, const string & sbjct, const string &body, unsigned id)
 : Message(athr, "Re: " + sbjct, body, id)
{} 
bool Reply::is_reply() const
{
   return true;
}
string Reply::to_formatted_string() const
{
   string Mess;               // write out Reply and put it all in string
   stringstream a;   // use str(); let message class deal with output
   a << "<begin_reply>" << endl;
   a << ":id: " << id << endl;
   a << ":subject: " << subject << endl;
   a << ":from: " << author << endl;
   if(child_list.size() > 0)
   {
      a << ":children: ";
      for(unsigned i = 0; i < child_list.size(); i++)
      {
         a << child_list.at(i)->get_id();
         if(i != child_list.size() - 1)
         {
            a << " ";
         }
      }
      a << endl;
   }
   a << ":body: " << body << endl;
   a << "<end>" << endl;
   Mess = a.str();
   return Mess;
}