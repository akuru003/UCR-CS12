//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<7>/main.cpp 
/// @brief Assignment<7> for CS 12 <Winter & 2015>
///
/// @author <Abraham Kuruvila> [akuru003@ucr.edu]
/// @date <3/12/2015>
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
#include "BBoard.h"
using namespace std;

int main(int argc, char **argv) // main tester for functions and board
{
   if(argc != 3)
   {
      cout << "ERROR: Invalid program call." << endl;
      return 1;
   }
   string userfile(argv[1]);
   string datafile(argv[2]);
   BBoard bb("CS12 Bulletin Board");
   if(!bb.load_users(userfile))
   {
      cout << "ERROR: Cannot load users from " << userfile << endl;
      return 1;
   }
   if(!bb.load_messages(datafile))
   {
      cout << "ERROR: Cannot load messages from " << datafile << endl;
      return 1;
   }
   bb.login();
   bb.run();
   if(!bb.save_messages(datafile))
   {
      cout << "ERROR: Cannot save messages to " << datafile << endl;
      return 1;
   }
   return 0;
}