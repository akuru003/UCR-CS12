/// @author <Abraham Kuruvila> [akuru003@ucr.edu]
/// @date <2/22/2015>
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
#include "IntList.h"
#include <iostream>
using namespace std;
IntList::IntList()
: head(0), tail(0)
{
}
IntList::~IntList()
{
   IntNode* tem;
   while(head)
   {
      tem = head;
      head = head->next;
      delete tem;
   }
}
void IntList::display() const
{
   IntNode* tem = head;
   IntNode* tem1 = tail;
   while(tem)
   {
      if(tem == tem1)
      {
         cout << tem->data;
         return;
      }
      cout << tem->data << " ";
      tem = tem->next;
   }
}
void IntList::push_front(int value)
{
   if(head == 0)
   {
      head = new IntNode(value);
      tail = head;
   }
   else
   {
      IntNode* tem = new IntNode(value);
      tem->next = head;
      head = tem;
   }
}
void IntList::pop_front()
{
   if(head == 0)
   {
      return;
   }
   else
   {
      IntNode* tem = head;
      head = head->next;
      delete tem;
   }
}