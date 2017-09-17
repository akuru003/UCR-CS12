#include <iostream>
#include "Distance.h"
#include <cmath>
using namespace std;

const Distance Distance::operator+(const Distance &a) const
{
   double j = convertToInches();
   double b = a.convertToInches();
   double l = j + b;
   Distance x(l);
   return x;
}
const Distance Distance::operator-(const Distance &a) const
{
   double j = convertToInches();
   double b = a.convertToInches();
   double l = j - b;
   if(l < 0.0)
   {
      l *= -1;
   }
   Distance x(l);
   return x;
}
double Distance::convertToInches() const
{
  double dist = 0.0;
  dist = (feet * 12) + inches;
  return dist;
}
void Distance::init() // sets feet and inches to proper amount
{
   int j = floor(inches / 12); 
   feet += j;
   inches = inches - (j * 12);
   return; 
}
Distance::Distance()
{
   feet = 0;
   inches = 0;
   return;
}
Distance::Distance(unsigned a, double b)
{
   Distance c;
   if(b < 0.0)
   {
      b *= -1;
   }
   if(b >= 12.0)
   {
      c.feet = a;
      c.inches = b;
      c.init();
      feet = c.feet;
      inches = c.inches;
      return;
   }
   feet = a;
   inches = b;
   return;
}
Distance::Distance(double a) 
{
   if(a < 0.0)
   {
      a *= -1;
   }
   feet = 0;
   inches = a;
   init();
   return;
}
void Distance::display() const
{
   cout << feet << "' " << inches << "\"" << endl;
}