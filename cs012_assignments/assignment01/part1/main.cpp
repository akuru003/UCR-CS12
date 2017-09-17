//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<1>/main.cpp 
/// @brief Assignment<1> for CS 12 <Winter & 2015>
///
/// @author <Abraham Kuruvila> [akuru003@ucr.edu]
/// @date <1/14/2015>
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
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;


/*This function generates a random double value between a and b*/
double randFloat (double a, double b)
{
   return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

int main()
{
   srand(333);
   int i = 0;
   double total = 0.0;
   double total1 = 0.0;
   double cal1 = 0.0;
   double cal2 = 0.0;
   double a = 0.0;
   double l[1000];
   double lx[100000];
   double b = 0.0;  // user entered
   double d = 0.0;  // user entered
   double calmean = 0.0;
   double calvari = 0.0;
   cout << "Enter one value" << endl;
   cin >> b;
   cout << "Enter another value" << endl;
   cin >> d;
   calmean = ((b + d)/2.0);          // gets theo mean
   calvari = ((pow((d - b),2))/12);   // gets theo vari
   for(i = 0; i < 1000; i++)
   {
      a = randFloat(b,d);             // assigns mean vals
      l[i] = a;
   }
   for(i = 0; i < 100000; i++)
   {
      a = randFloat(b,d);             // assigns mean vals
      lx[i] = a;
   }
   for(i = 0; i < 1000; i++)
   {
      total += l[i];               // tallies up sums 
   }
   total /= 1000;
   for(i = 0; i < 100000; i++)
   {
      total1 += lx[i];             // tallies up sums
   }
   total1 /= 100000;  // means are good
   
    for(i = 0; i < 1000; i++)
   {                              // gen ran num - mean 
      a = l[i];
      a -= total;
      a = pow(a,2);
      cal1 += a;
   }
   cal1 /= 1000;
   for(i = 0; i < 100000; i++)
   {
      a = lx[i];
      a -= total1;
      a = pow(a,2);
      cal2 += a;
   }
   cal2 /= 100000;
   cout << calmean  << ' ' << total << ' ' << calvari << ' ' << cal1 << endl;
   cout << calmean  << ' ' << total1 << ' ' << calvari << ' ' << cal2 << endl;
   return 0;
} 
