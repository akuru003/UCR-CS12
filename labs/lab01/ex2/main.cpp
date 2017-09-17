//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab1.cpp 
/// @brief Lab 1 Exercise 2
///
/// @author Test Student [akuru003@ucr.edu]
/// @date January 06, 2014
//  ================== END ASSESSMENT HEADER ===============
// This program implements the Monte Carlo Method for estimating the value of PI.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
 
// given the coordinates of a point (x,y) computes if the point is inside the circle 
// centered at origin with radius R. Returns 'true' if it is inside, 'false' otherwise.
bool is_inside(double x, double y, double R)
{
     double l = 0.0;
     l = sqrt((pow(x,2) + pow(y,2)));
     if(l <= 500)
     {
        return true;
     }
     else
     {
        return false;
     }
}
 
// given the side,s, of a square that is centered at origin, 
// chooses a random coordinates inside the square, and calls is_inside function 
// to test if the point is inside the circle or not.
bool throw_dart(int s)
{
   int x, y; 
   bool side;
   int z = s/2;
   int a = (s/2) * -1;
   // assign x and y to two random numbers between -s/2 and s/2
   x = (rand() % (z - a + 1)) + a;
   y = (rand() % (z - a + 1)) + a;
   side = is_inside(x,y,z);
   if(side)
   {
       return true;
   }
   else
   {
       return false;
   }
   // see the previous exercise to see an example. 

   //Call the is_inside function and return its output. 

   //You do not have to cast x,y to floats, it is done automatically.
}
int main()
{
   srand(time(0));
   bool dart;
   double pi = 0.0;
   int side = 1000; // this is the side of the square and is also our resolution. 
   int tries; // this is the number of tries.
   //Ask the user for the number of tries using cout.
   cout << "How many tries?" << endl;
   //Get the users input using cin.
   cin >> tries;
   int in_count = 0; //counter to track number of throws that fall inside
   for(int i = 0; i < tries; i++)
   {
       dart = throw_dart(side);
       if(dart)
       {
           in_count++;
       }
       //throw a dart using throw_dart method and increment the counter depending on its output.
   }
   //Compute and display the estimated value of PI. Make sure you are not doing integer division.
   pi = ((static_cast<double>(4 * in_count))/(static_cast<double>(tries)));
   cout << "pi is " << pi << endl;
   return 0;
}