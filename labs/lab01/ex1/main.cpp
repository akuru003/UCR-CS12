//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab1.cpp 
/// @brief Lab 1 Exercise 1
///
/// @author Test Student [akuru003@ucr.edu]
/// @date January 06, 2014
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
   srand(time(0));
   int number_to_guess = rand() % 100;
   cout << "Guess a number between 1 and 100." << std::endl << "? ";
   int guess;
   cin >> guess;
   while (number_to_guess != guess )
   {
      if (guess > number_to_guess )
      {
         cout << "Try lower." << endl << "? ";
      }
      else if ( guess < number_to_guess )
      {
         cout << "Try Higher." << endl << "? ";
      }
      cin >> guess;
   }
   cout << "You guessed right!!!" << endl;
   return 0;
}