//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<1>/main.cpp 
/// @brief Assignment<1> for CS 12 <Winter & 2015>
///
/// @author <Abraham Kuruvila> [akuru003@ucr.edu]
/// @date <1/15/2015>
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
double rand_mv(double mean, double var)
{
    double a = mean;
    double b = var; 
    b = (( 2 * mean) + (sqrt(12 * var))) / 2;
    a = (mean * 2) - b;
    cout << a << ' ' << b << endl;
    return randFloat(a,b);
}
int main()
{
   srand(333);
   double a = 0.0;
   double b = 0.0;
   double random = 0.0;
   cout << "Enter mean: " << endl;
   cin >> a;
   cout << "Enter variance: " << endl;
   cin >> b;
   random = rand_mv(a,b);
   return 0;
} 