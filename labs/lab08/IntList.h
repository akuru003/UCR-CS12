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
#ifndef INTVLIST_H
#define INTLIST_H

struct IntNode // struct's are always default public class - private
{
   int data;
   IntNode *next;
   IntNode(int data) 
   : data(data), next(0)
   {
   }
};

class IntList
{
   private:
   IntNode* head;
   IntNode* tail;
   public:
   IntList();
   ~IntList();
   void display() const;
   void push_front(int value); 
   void pop_front();
};
#endif
