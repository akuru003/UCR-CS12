//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab1.cpp 
/// @brief Lab 1 Exercise 3
///
/// @author Test Student [akuru003@ucr.edu]
/// @date January 06, 2014
//  ================== END ASSESSMENT HEADER ===============
// This program implements the Monte Carlo Method for estimating the value of PI.
#include <iostream>
#include <vector>
using namespace std;

void remov(vector<int>& v1, int b)
{
   for(int i = b; i < v1.size() - 1; i++)
   {                                     
      v1.at(i) = v1.at(i + 1);
   }
   v1.pop_back();
}
int search(vector<int>& v, int a)
{
   int returned = -1;
   for(int i = 0; i < v.size(); i++)
   {
      if((v.at(i) == a) && (returned == -1))
      {
         returned = i;
         remov(v,i);
      }
   }
   return returned;
}
int main()
{
   vector<int> v;
   int num = 0;
   int numremove = 0;
   int numfound = 0;
   cout << "Please enter in integers (0 to stop): ";
   do
   {
      cin >> num;
      if(num != 0)
      {
         v.push_back(num); 
      }
   }
   while(num != 0);
   cout << "What number would you like to find and remove?: ";
   cin >> numremove;
   numfound = search(v,numremove);
   cout << "Found:" << numfound << endl;
   cout << "Result: ";
   for(int i = 0; i < v.size(); i++)
   {
       cout << v.at(i) << ' ';
   }
   cout << endl;
   return 0;
}