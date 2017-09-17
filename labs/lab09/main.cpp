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
#include <iostream>
#include "Music_collection.h"
using namespace std;

int main()
 {
   Music_collection A;
   Music_collection B(A); 
   Music_collection C;
   C = B;
   cout << A << B << C;
   return 0;
}