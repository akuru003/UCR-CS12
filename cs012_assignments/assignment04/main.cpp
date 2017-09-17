//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<3>/main.cpp 
/// @brief Assignment<4> for CS 12 <Winter & 2015>
///
/// @author <Abraham Kuruvila> [akuru003@ucr.edu]
/// @date <2/9/2015>
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
#include <cstdlib> 
#include "BBoard.h"
using namespace std;

int main(int argc, char* argv[])
{
   if(argc != 2)
   {
      cout << "Usage: myprog.exe inputFileName" << endl;
      exit(0);
   }
   BBoard bb("Jack's Amazing Bulletin Board"); 
   string name = argv[1];
   bb.setup(name);
   bb.login();
   bb.run();
   return 0;
}

