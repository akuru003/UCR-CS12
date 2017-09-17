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
#include "IntVector.h"
#include <iostream>
#include <cstdlib> 
using namespace std;

IntVector::IntVector()
: sz(0), cap(0), data(0)
{
    
}
IntVector::IntVector(unsigned size)
: sz(size), cap(size), data(new int[size])
{
   for(int i = 0; i < size; i++) 
   {
      data[i] = 0;    
   } 
   return;
}
IntVector::IntVector(unsigned size, int value)
: sz(size), cap(size), data(new int[size])
{
   for(int i = 0; i < size; i++) 
   {
      data[i] = value;    
   } 
   return;
}
IntVector::~IntVector()
{
   delete [] data; 
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
int& IntVector::at(unsigned index)
{
   if(index >= sz)
   {
      exit(1);
   }
   return data[index];
}
void IntVector::insert(unsigned index, int value)
{
   
   if(index > sz)
   {
      exit(1);
   }
   if(sz == 0)
   {
      expand(1);
   }
   else if(sz >= cap)
   {
      expand();
   }
   data[sz] = value;
   sz++;
   for(int i = (sz - 1); i > index; i--)
   {
      swap(data[i], data[i - 1]);
   }
}
void IntVector::erase(unsigned index)
{
   if(index >= sz)
   {
      exit(1);
   }
   for(int i = index; i < sz - 1; i++)
   {
      swap(data[i], data[i + 1]);
   }
   sz--;
}
const int& IntVector::front() const
{
   return data[0];
}
int& IntVector::front()
{
   return data[0];
}
const int& IntVector::back() const
{
   return data[sz - 1];
}
int& IntVector::back()
{
   return data[sz - 1];
}
void IntVector::assign(unsigned n, int value)
{
   if(n > cap)
   {
      if((cap * 2) > (n))
      {
         expand();
      }
      else
      {
         expand(n - cap);
      }
   }
   sz = n;
   for(int i = 0; i < sz; i++)
   {
      data[i] = value;
   }
}
void IntVector::push_back(int value)
{
   if(cap == 0)
   {
      expand();
   }
   if(sz >= cap)
   {
      expand();
      sz++;
   }
   else
   {
      sz++;
   }
   data[sz - 1] = value;
}
void IntVector::pop_back()
{
   if(sz == 0)
   {
      exit(1);
   }
   sz--;
}
void IntVector::clear()
{
   sz = 0;
}
void IntVector::resize(unsigned size)
{
   if(size <= sz)
   {
      sz = size;
   }
   if(size > sz)
   {
      if(size > cap)
      {
         if((cap * 2) > (size))
         {
            expand();
         }
         else
         {
            expand(size - cap);
         }
      }
      for(int i = sz; i < size; i++)
      {
         data[i] = 0;
      }
      sz = size;
   }
}
void IntVector::resize(unsigned size, int value)
{
   if(size <= sz)
   {
      sz = size;
   }
   if(size > sz)
   {
      if(size > cap)
      {
         if((cap * 2) > (size))
         {
            expand();
         }
         else
         {
            expand(size - cap);
         }
      }
      for(int i = sz; i < size; i++)
      {
         data[i] = value;
      }
      sz = size;
   }
}
void IntVector::reserve(unsigned n)
{
   if(n > cap)
   {
      if((cap * 2) > (n))
      {
         expand();
      }
      else
      {
         expand(n - cap);
      }
   }
}
void IntVector::expand()
{
   if(sz == 0)
   {
      expand(1);
      return;
   }
   int* a = new int[cap * 2];
   for(int i = 0; i < cap; i++)
   {
      a[i] = data[i];
   }
   delete [] data;
   data = a;
   cap *= 2;
}
void IntVector::expand(unsigned amount)
{
   int* a = new int[cap + amount];
   for(int i = 0; i < cap; i++)
   {
      a[i] = data[i];
   }
   delete [] data;
   data = a;
   cap += amount;
}
















