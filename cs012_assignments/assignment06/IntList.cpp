/// @author <Abraham Kuruvila> [akuru003@ucr.edu]
/// @date <2/26/2015>
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
   while(head) // same as saying head != zero i guess cuz zero is a nono in pointers
   {
      tem = head;
      head = head->next;
      delete tem;
   }
}
void IntList::display() const
{
   if(!head)
   {
      return;
   }
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
   if(!head)
   {
      tail = 0;
   }
}
void IntList::push_back(int value)
{
  if(head == 0)
  {
      head = new IntNode(value);
      tail = head;
   }  
   else
   {
      tail->next = new IntNode(value);
      tail = tail->next;
   }
}
void IntList::select_sort()
{
   if(!head)
   {
      return;
   }
   IntNode* temp = head;
   for(temp; temp != 0; temp = temp->next)
   {
      IntNode* small = temp;
      IntNode* min = temp;
      for(min; min != 0; min = min->next)
      {
         if(min->data < small->data)
         {
            small = min;
         }
      }
      int num = temp->data;
      temp->data = small->data;
      small->data = num;
   }
}
void IntList::insert_sorted(int value)
{
   if(!head)
   {
      push_front(value);
   }
   else if(head->next == 0)
   {
      if(head->data <= value)
      {
         push_back(value);
      }
      else
      {
         push_front(value);
      }
   }
   else if(head->data >= value)
   {
      push_front(value);
   }
   else if(tail->data <= value)
   {
      push_back(value);
   }
   else
   {
      IntNode* b = head;
      IntNode* t = head->next;
      IntNode* i = 0;
      IntNode* temp = new IntNode(value);
      for(i = head; !((b->data <= value) && (value <= t->data)); i = i->next)
      {
         b = i->next;
         t = i->next->next;
      }
      temp->next = t;
      b->next = temp;
   }
}
void IntList::remove_duplicates()
{
   for(IntNode* tem = head; tem != 0; tem = tem->next)
   {
      int tracker = tem->data;
      IntNode* back = tem;
      IntNode* tem2 = tem->next;
      while(tem2 != 0)
      {
         if(tracker == tem2->data && tem2->next !=0)
         {
            back->next = tem2->next;
            delete tem2;
            tem2 = back;
         }
         else if(tracker == tem2->data && tem2 == tail)
         {
            tail = back;
            delete tem2;
            tail->next = 0;
         }
         if(tem2 == back)
         {
            tem2 = tem2->next;
         }
         else
         {
            tem2 = tem2->next;
            back = back->next;
         }
      }
   }
}