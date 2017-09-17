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
#include "BBoard.h"
#include "User.h"
#include "Message.h"
#include "Topic.h"
#include "Reply.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

string un = "";
BBoard::BBoard()
: title("Jack's Amazing Bulletin Board"), current_user(0)
{}

BBoard::BBoard(const string &ttl)
: title(ttl), current_user(0)
{}

BBoard::~BBoard()
{
   for(unsigned i = 0; i < message_list.size(); i++)
   {
      if(message_list.at(i) != 0)
      {
         delete message_list.at(i);
      }
   }  
}
bool BBoard::load_users(const string &userfile)
{
   ifstream inf;  
   string a, b = "";
   inf.open(userfile.c_str());
   if(!inf.is_open())
   {
      return false;
   }
   inf >> a;
   while(a != "end")
   {
      inf >> b;
      User u(a,b);
      user_list.push_back(u);
      inf >> a;
   }
   inf.close();
   return true;
}
bool BBoard::load_messages(const string& datafile)
{
   ifstream inf;
   stringstream a;
   string author, subject, body, kid, next;
   unsigned id, cid, nummessages = 0;;
   Message *Top = 0, *Rep = 0;
   vector<string> kids;
   inf.open(datafile.c_str());
   if(!inf.is_open())
   {
      return false;
   }
   inf >> nummessages;
   if(nummessages == 0)
   {
      return true;
   }
	while(!inf.eof())
	{
      inf >> next;
		if(next == "<begin_topic>")
		{
			while(next != "<end>")
			{
				inf >> next;
				if(next == ":id:")
				{
					inf >> id;
				}
				else if(next == ":subject:")
				{
					inf.get();
					getline(inf, subject);
				}
				else if(next == ":from:")
				{
					inf >> author;
				}
				else if(next == ":children:")
				{
					getline(inf, next);
					kids.push_back(next);
				}
				else if(next ==":body:")
				{
				   body = "";
					inf.get();
					while(next != "<end>")
					{
					   getline(inf, next);
						if(next != "<end>")
						{
						   body += next;
						}
						inf >> next;
						if(next != "<end>")
						{
						   body += ("\n" + next);
						}
					}
					if(body.size() != 0 && body.at(body.size() - 1) == '\n')
					{
						body.erase(body.size() - 1);
					}
					kid = "0";
					kids.push_back(kid);
				}
			}
			Top = new Topic(author, subject, body, id);
			message_list.push_back(Top);
		}
		else if(next == "<begin_reply>")
		{
		   while(next != "<end>")
			{
				inf >> next;
				if(next == ":id:")
				{
					inf >> id;
				}
				else if(next == ":subject:")
				{
					inf.get();
					inf >> next;
					inf.get();
					getline(inf, subject);
				}
				else if(next == ":from:")
				{
					inf >> author;
				}
				else if(next == ":children:")
				{
					getline(inf, next);
					kids.push_back(next);
				}
				else if(next ==":body:")
				{
			   	body = "";
					inf.get();
					while(next != "<end>")
					{
						getline(inf, next);
						if(next != "<end>")
						{
						   body += next;  
						}
						inf >> next;
						if(next != "<end>")
						{
								body += ("\n" + next);
						}
					}
					if(body.size() != 0 && body.at(body.size() -1) == '\n')
					{
						body.erase(body.size() -1);
					}
					kid = "0";
					kids.push_back(kid);
				}
			}
			Rep = new Reply(author, subject, body, id);
			message_list.push_back(Rep);
			
		}
	}
   for(unsigned i = 0; i < kids.size(); i++)
	{
	   a << kids.at(i) << endl;
	}
	for(unsigned i = 0; i < nummessages; i++)
	{
		while(true)
		{
			a >> cid;
			if(cid == 0)
			{
			   break;
			}
			message_list.at(i)->add_child(message_list.at(cid - 1));
		}
	}
	inf.close();
	return true;
}
bool BBoard::save_messages(const string& datefile)
{
   ofstream outF;
   outF.open(datefile.c_str());
   if(!outF.is_open())
   {
      return false;
   }
   outF << message_list.size() << endl;
   for(unsigned i = 0; i < message_list.size(); i++)
   {
      outF << message_list.at(i)->to_formatted_string();
   }
   outF.close();
   return true;
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
         return;
      }
      cout << "Enter your password: ";
      cin >> pass;
      for(unsigned i = 0; i < user_list.size(); i++)
      {
         if(user_list.at(i).check(un,pass))
         {
            counter++;
            un = user_list.at(i).get_username();
            current_user = &user_list.at(i);
         }
      }
      if(counter != 0)
      {
         cout << "Welcome back " << un << '!' << endl;
         cout << endl;
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
   if(current_user == 0)
   {
      return;
   }
   string line = "-----------------------------------------------";
   string check = "";
   do
   {
      string letter = "";
      do
      {
         cout << "Menu" << endl;
         cout << "  - Display Messages ('D' or 'd')" << endl;
         cout << "  - Add New Topic('N' or 'n')" << endl;
         cout << "  - Add Reply('R' or 'r')" << endl;
         cout << "  - Quit ('Q' or 'q')" << endl;
         cout << "Choose an action: ";
         cin >> letter;
      }
      while((letter != "D") && (letter != "d") && (letter != "N")
      && (letter != "n") && (letter != "R") && (letter != "r")
      && (letter != "Q") && (letter != "q"));
      if((letter == "D") || (letter == "d"))
      {
         if(message_list.size() == 0)
         {
            cout << endl;
            cout << "Nothing to Display." << endl;
         }
         else
         {
            for(unsigned i = 0; i < message_list.size(); i++)
            {
               if(!message_list.at(i)->is_reply())
               {
                  cout << line << endl;
                  message_list.at(i)->print(0);
               }
            }
            cout << line << endl;
         }
      }
      if((letter == "N") || (letter == "n"))
      {
         add_topic();
      }
      if((letter == "R") || (letter == "r"))
      {
         add_reply();
      }
      if((letter == "Q") || (letter == "q"))
      {
         cout << "Bye!" << endl;
         check == "done";
         return;
      }
   }
   while(check == "");
}
void BBoard::add_topic()
{
   string subject, body = "";
   cout << "Enter a subject: ";
   cin.ignore();
   getline(cin, subject);
   cout << "Enter a body: ";
   getline(cin,body);
   Topic *Tp = new Topic(un, subject, body, message_list.size() + 1);
   message_list.push_back(Tp);
   cout << "Topic Recorded!" << endl << endl;
}
void BBoard::add_reply()
{
   int index = 0;
   string body, subject, temp = "";
   int num = 0;
   int size = message_list.size();
   if(message_list.size() == 0)
   {
      cout << "No messages to reply to!" << endl;
      cout << endl;
      return;
   }
   while(index == 0)
   {
      cout << "Enter Message ID (-1 for the menu): ";
      cin >> num;
      if(num == -1)
      {
         return;
      }
      else if((num == 0) || (num > size))
      {
         cout << "Invalid Message Id!" << endl << endl;
      }
      else
      {
         index = 1;
      }
   }
   subject = message_list.at(num - 1)->get_subject();
   cin.ignore();
   cout << "Enter body: ";
   getline(cin, body);
   Reply *Rp = new Reply(un, subject, body, size + 1);
   message_list.at(num - 1)->add_child(Rp);
   message_list.push_back(Rp);
   cout << endl;
}