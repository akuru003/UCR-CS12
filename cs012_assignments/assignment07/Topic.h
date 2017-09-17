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
#ifndef TOPIC_H
#define TOPIC_H
#include <iostream>
#include "Message.h"
using namespace std;

class Topic : public Message
{
   public:
   Topic();
   Topic(const string &athr,const string &sbjct,const string &body,unsigned id);
   virtual bool is_reply() const; 
   virtual string to_formatted_string() const;
};
#endif