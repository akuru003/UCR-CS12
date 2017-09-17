/// @author <Abraham Kuruvila> [akuru003@ucr.edu]
/// @date <2/14/2015>
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
#include "IntVector.h"
#include <iostream>
#include <cstdlib> 
using namespace std;

IntVector::IntVector()
: sz(0), cap(0), data(NULL)
{
    
}
IntVector::IntVector(unsigned size)
: sz(size), cap(size), data(new int[size])
{
   int i = 0;
   for(i = 0; i < size; i++) 
   {
      data[i] = 0;    
   } 
   return;
}
IntVector::IntVector(unsigned size, int value)
: sz(size), cap(size), data(new int[size])
{
   int i = 0;
   for(i = 0; i < size; i++) 
   {
      data[i] = value;    
   } 
   return;
}
unsigned IntVector::size() const
{
   return sz;
}
unsigned IntVector::capacity() const
{
   return cap;
}
bool IntVector::empty() const
{
   if(sz == 0)
   {
      return true;
   }
   return false;
}
const int& IntVector::at(unsigned index) const
{
   if(index >= sz)
   {
      exit(1);
   }
   return data[index];
}


















