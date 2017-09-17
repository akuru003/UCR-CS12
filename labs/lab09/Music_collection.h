/// @author <Abraham Kuruvila> [akuru003@ucr.edu]
/// @date <3/3/2015>
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
#ifndef MUSIC_COLLECTION_H
#define MUSIC_COLLECTION_H
#include <iostream>
using namespace std;

class Tune
{
 private:
 string title;
 public:
 Tune()
 :title()
 {}
 Tune(const string &n)
 :title(n)
 {} 
 const string & get_title() const 
 {
    return title;
 }
};

class Music_collection
{
   private: 
   int number;  
   int max; 
   Tune *collection;  // just the title
   public:
   Music_collection(); 
   Music_collection(int n); 
   Music_collection(const Music_collection &m);
   bool add_tune(const Tune &t);
   bool set_tune( int index, const Tune &t);
   Music_collection & operator=(const Music_collection &m);
   ~Music_collection();
   friend ostream & operator<<(ostream &out, const Music_collection &m); 
};
#endif