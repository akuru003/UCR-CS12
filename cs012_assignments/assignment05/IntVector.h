/// @author <Abraham Kuruvila> [akuru003@ucr.edu]
/// @date <2/18/2015>
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
#ifndef INTVECTOR_H
#define INTVECTOR_H
#include <iostream>
using namespace std;

class IntVector
{
   private:
   unsigned sz;
   unsigned cap;
   int* data;
   public:
   IntVector();
   IntVector(unsigned size);
   IntVector(unsigned size, int value);
   ~IntVector();
   unsigned size() const;
   unsigned capacity() const;
   bool empty() const;
   const int & at(unsigned index) const;
   int & at(unsigned index);
   void insert(unsigned index, int value);
   void erase(unsigned index);
   const int & front() const;
   int & front();
   const int & back() const;
   int & back();
   void assign(unsigned n, int value);
   void push_back(int value);
   void pop_back();
   void clear();
   void resize(unsigned size);
   void resize(unsigned size, int value);
   void reserve(unsigned n);
   private:
   void expand();
   void expand(unsigned amount);
};
#endif






















