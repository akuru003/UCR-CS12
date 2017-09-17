#include "BBoard.h"
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iostream>
using namespace std;

string un = "";
BBoard::BBoard()
: title("Jack's Amazing Bulletin Board"), current_user(User())
{
  
}
BBoard::BBoard(const string &ttl)
: title(ttl), current_user(User())
{

}
void BBoard::setup(const string &input_file)
{
   ifstream inf(input_file.c_str());  
   string a, b = "";
   while(inf >> a >> b)
   {
      User u(a,b);
      user_list.push_back(u);
   }
}
void BBoard::login() 
{
   cout << "Welcome to " << title << endl;
   int counter = 0;
   do
   {
      cout << "Enter your username ('Q' or 'q' to quit): ";
      string pass = "";
      cin >> un;
      if((un == "q") || (un == "Q"))
      {
         cout << "Bye!" << endl;
         exit(0);
      }
      cout << "Enter your password: ";
      cin >> pass;
      for(int i = 0; i < user_list.size(); i++)
      {
         if(user_list.at(i).check(un,pass))
         {
            counter++;
            un = user_list.at(i).get_username();
         }
      }
      if(counter != 0)
      {
         cout << "Welcome back " << un << '!' << endl;
      }
      if(counter == 0)
      {
         cout << "Invalid Username or Password!" << endl;
         cout << endl;
      }
   }
   while(counter == 0);
}
void BBoard::run()
{
   string check = "";
   do
   {
      string letter = "";
      do
      {
         cout << "Menu" << endl;
         cout << "  - Display Messages ('D' or 'd')" << endl;
         cout << "  - Add New Message ('N' or 'n')" << endl;
         cout << "  - Quit ('Q' or 'q')" << endl;
         cout << "Choose an action: ";
         cin >> letter;
      }
      while(letter == "");
      if((letter == "Q") || (letter == "q"))
      {
         cout << "Bye!" << endl;
         check == "done";
         exit(0);
      }
      if((letter == "D") || (letter == "d"))
      {
         if(message_list.size() == 0)
         {
            cout << endl;
            cout << "Nothing to Display." << endl;
         }
         else
         {
            cout << endl;
            cout << "-----------------------------------------------" << endl;
            for(int i = 0; i < message_list.size(); i++)
            {
               cout << "Message #" << i + 1 << ": ";
               message_list.at(i).display();
               cout << "-----------------------------------------------";
               cout << endl;
            }
         }
      }
      if((letter == "N") || (letter == "n"))
      {
         Message Mess;
         string sub, body = "";
         string user = un;
         cout << "Enter Subject: ";
         cin.ignore();
         getline(cin, sub);
         cout << "Enter Body: ";
         getline(cin, body);
         Mess = Message(user, sub, body);
        message_list.push_back(Mess);
        cout << "Message Recorded!" << endl << endl;
      }
   }
   while(check == "");
}