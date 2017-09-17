//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<2>/main.cpp 
/// @brief Assignment<2> for CS 12 <Winter & 2015>
///
/// @author <Abraham Kuruvila> [akuru003@ucr.edu]
/// @date <1/21/2015>
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
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
   double e[6][8] = {};
   ifstream infile;
   ofstream outfile;
   string filename;
   string filename1;
   double top,right,bottom,left, tolerance,temp = 0.0;
   int dif = 0;
   double di = 4.0;
   cout << "What is the input file? " << endl;
   cin >> filename;
   infile.open(filename.c_str());
   if(!infile)  
   {
      cout << "Error opening " << filename << endl;
      return 0;
   }
   cout << "What is the output file? " << endl;
   cin >> filename1;
   outfile.open(filename1.c_str());
   if(!outfile)  
   {
      cout << "Error opening " << filename1 << endl;
      return 0;
   }
   infile >> top;
   infile >> right;
   infile >> bottom;
   infile >> left;
   infile >> tolerance;
   for(int i = 0; i < 8; i++)  // sets top
   {
      e[0][i] = top;
   }
   for(int i = 1; i < 5; i++)  // sets left
   {
      e[i][0] = left;
   }
   for(int i = 1; i < 5; i++) // sets right
   {
      e[i][7] = right;
   }
   for(int i = 0; i < 8; i++) // sets bottom
   {
      e[5][i] = bottom;
   }
   do
   {
      dif = 0;;
      for(int r = 1; r < 5; r++)
      {
         for(int c = 1; c < 7; c++)
         {
            temp = e[r][c];
            e[r][c] = (e[r + 1][c] + e[r - 1][c] + e[r][c + 1] + e[r][c -1])/di;
            if((e[r][c] - temp) > tolerance)
            {
               dif = 1;
            }
         }
      }
   }
   while(dif == 1);
   for(int r = 1; r < 5; r++)
   {
      for(int c = 1; c < 7; c++)
      {
         outfile << e[r][c] << "   ";
      }
      outfile << endl;
   }
   return 0;
}