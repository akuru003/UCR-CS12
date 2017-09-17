#include <iostream> // implementation file
#include "Date.h" // Date class
using namespace std;

bool Date::isLeap(unsigned year) const // for leap year
{
   int counter = 0;
   if(year % 4 == 0)
   {
      counter = 5;
      if(year % 100 == 0)
      {
         counter = 10;
         if(year % 400 == 0)
         {
            counter = 15;
         }
      }
   }
   if(counter == 5)
   {
      return true;
   }
   else if(counter == 10)
   {
      return false;
   }
   else if(counter == 15)
   {
      return true;
   }
   else
   {
      return false;
   }
}
unsigned Date::daysPerMonth(unsigned m, unsigned year) const // # days in month
{
   if((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) ||
   (m == 10) || (m == 12))
   {
      return 31;
   }
   else if((m == 4) || (m == 6) || (m == 9) || (m == 11))
   {
      return 30;
   }
   else if(m == 2)
   {
      if(isLeap(year))
      {
         return 29;
      }
      else
      {
         return 28;
      }
   }
   return 0;
}
string Date::name(unsigned m) const // number to month
{
   if(m == 1)
   {
      return "January";
   }
   else if(m == 2)
   {
      return "February";
   }
   else if(m == 3)
   {
      return "March";
   }
   else if(m == 4)
   {
      return "April";
   }
   else if(m == 5)
   {
      return "May";
   }
   else if(m == 6)
   {
      return "June";
   }
   else if(m == 7)
   {
      return "July";
   }
   else if(m == 8)
   {
      return "August";
   }
   else if(m == 9)
   {
      return "September";
   }
   else if(m == 10)
   {
      return "October";
   }
   else if(m == 11)
   {
      return "November";
   }
   else if(m == 12)
   {
      return "December";
   }
   return "";
}
unsigned Date::number(const string &mn) const // month to number
{
   if((mn == "January") || (mn == "january"))
   {
      return 1;
   }
   else if((mn == "February") || (mn == "february"))
   {
      return 2;
   }
   else if((mn == "March") || (mn == "march")) 
   {
      return 3;
   }
   else if((mn == "April") || (mn == "april"))
   {
      return 4;
   }
   else if((mn == "May") || (mn == "may"))
   {
      return 5;
   }
   else if((mn == "June") || (mn == "june"))
   {
      return 6;
   }
   else if((mn == "July") || (mn == "july"))
   {
      return 7;
   }
   else if((mn == "August") || (mn == "august"))
   {
      return 8;
   }
   else if((mn == "September") || (mn == "september"))
   {
      return 9;
   }
   else if((mn == "October") || (mn == "october"))
   {
      return 10;
   }
   else if((mn == "November") || (mn == "november"))
   {
      return 11;
   }
   else if((mn == "December") || (mn == "december"))
   {
      return 12;
   }
   return 0;
}
Date::Date() // first constructor
{
   monthName = "January";
   day = 1;
   month = 1;
   year = 2000;
   return;
}
Date::Date(unsigned m, unsigned d, unsigned y) // second constructor
{
   int counter = 0;
   if(m > 12)
   {
      m = 12;
      counter++;
   }
   int d1 = daysPerMonth(m,y);
   if(d > d1)
   {
      d = d1;
      counter++;
   }
   month = m;
   day = d;
   year = y;
   monthName = name(m);
   if(counter > 0)
   {
      cout << "Invalid date values: Date corrected to " << month << '/' << day 
      << '/' << year << '.' << endl;
   }
   return;
}
Date::Date(const string &mn, unsigned d, unsigned y) // third constructor
{
   int j = number(mn); // takes in name for number
   int counter = 0;
   if(j == 0)
   {
      cout << "Invalid month name: the Date was set to 1/1/2000" << endl;
      day = 1;
      month = 1;
      year = 2000;
      monthName = "January";
      return;
   }
   int d1 = daysPerMonth(j,y);
   if(d > d1)
   {
      d = d1;
      counter++;
   }
   monthName = name(j);
   day = d;
   year = y;
   month = j;
   if(counter > 0)
   {
      cout << "Invalid date values: Date corrected to " << month << '/' << day 
      << '/' << year << '.' << endl;
   }
   return;
}
void Date::printNumeric() const // prints 1/2/2222
{
   cout << month << '/' << day << '/' << year;
   return;
}
void Date::printAlpha() const // prints jan/1/1222
{
   cout << monthName << ' ' << day << ", " << year;
   return;
}
Date Date::addDays(int num) const
{
   Date a;
   int incredays = num; // takes in incredays
   a.month = month;
   a.day = day;
   a.year = year;
   a.monthName = "";
   if(incredays >= 0)
   {
      int counter = 0;
      for(int i = 0; i < incredays; i++)
      {
         if(a.month == 1)
         {
            if(a.day == 31)
            {
               a.day = 1;
               a.month++;
               counter++;
            }
         }
         else if(a.month == 2)
         {
            if(isLeap(a.year))
            {
               if(a.day == 29)
               {
                  a.day = 1;
                  a.month++;
                  counter++;
               }  
            }
            else
            {
               if(a.day == 28)
               {
                  a.day = 1;
                  a.month++;
                  counter++;
               }
            }
         }
         else if(a.month == 3)
         {
            if(a.day == 31)
            {
               a.day = 1;
               a.month++;
               counter++;
            }
         }
         else if(a.month == 4)
         {
            if(a.day == 30)
            {
               a.day = 1;
               a.month++;
               counter++;
            }
         }  
         else if(a.month == 5)
         {
            if(a.day == 31)
            {
               a.day = 1;
               a.month++;
             counter++;   
            }
         }
         else if(a.month == 6)
         {
            if(a.day == 30)
            {
               a.day = 1;
               a.month++;
               counter++;
            }
         }
         else if(a.month == 7)
         {
            if(a.day == 31)
            {
               a.day = 1;
               a.month++;
               counter++;
            }
         }
         else if(a.month == 8)
         {
            if(a.day == 31)
            {
               a.day = 1;
               a.month++;
               counter++;
            }
         }
         else if(a.month == 9)
         {
            if(a.day == 30)
            {
               a.day = 1;
               a.month++;
               counter++;
            }
         }
         else if(a.month == 10)
         {
            if(a.day == 31)
            {
               a.day = 1;
               a.month++;
               counter++;
            }
         }
         else if(a.month == 11)
         {
            if(a.day == 30)
            {
               a.day = 1;
               a.month++;
               counter++;
            }
         }
         else if(a.month == 12)
         {
            if(a.day == 31)
            {
               a.day = 1;
               a.month = 1;
               a.year++;
               counter++;
            }  
         }
         if(counter == 0)
         {
            a.day++;
         }
         counter = 0;
      }
      a.monthName = name(a.month);
   }
   else if(incredays < 0)
   {
      int l = -1 * num;
      int counter = 0;
      for(int i = 0; i < l; i++)
      {
         if(a.month == 1)
         {
            if(a.day == 1)
            {
               a.day = 31;
               a.month = 12;
               a.year--;
               counter++;
            }
         }
         else if(a.month == 2)
         {
            if(a.day == 1)
            {
               a.day = 31;
               a.month--;
               counter++;
            }
         }
         else if(a.month == 3)
         {
            if(isLeap(a.year))
            {
               if(a.day == 1)
               {
                  a.day = 29;
                  a.month--;
                  counter++;
               }  
            }
            else
            {
               if(a.day == 1)
               {
                  a.day = 28;
                  a.month--;
                  counter++;
               }
            }
         }
         else if(a.month == 4)
         {
            if(a.day == 1)
            {
               a.day = 31;
               a.month--;
               counter++;
            }
         }  
         else if(a.month == 5)
         {
            if(a.day == 1)
            {
               a.day = 30;
               a.month--;
               counter++;   
            }
         }
         else if(a.month == 6)
         {
            if(a.day == 1)
            {
               a.day = 31;
               a.month--;
               counter++;
            }
         }
         else if(a.month == 7)
         {
            if(a.day == 1)
            {
               a.day = 30;
               a.month--;
               counter++;
            }
         }
         else if(a.month == 8)
         {
            if(a.day == 1)
            {
               a.day = 31;
               a.month--;
               counter++;
            }
         }
         else if(a.month == 9)
         {
            if(a.day == 1)
            {
               a.day = 31;
               a.month--;
               counter++;
            }
         }
         else if(a.month == 10)
         {
            if(a.day == 1)
            {
               a.day = 30;
               a.month--;
               counter++;
            }
         }
         else if(a.month == 11)
         {
            if(a.day == 1)
            {
               a.day = 31;
               a.month--;
               counter++;
            }
         }
         else if(a.month == 12)
         {
            if(a.day == 1)
            {
               a.day = 30;
               a.month--;
               counter++;
            }  
         }
         if(counter == 0)
         {
            a.day--;
         }
         counter = 0;
      }
       a.monthName = name(a.month);
   }
   return a;
}