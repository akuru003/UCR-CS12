/// @author <Abraham Kuruvila> [akuru003@ucr.edu]
/// @date <3/9/2015>
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
using namespace std;

void reverse(string &s, int num, int size)
{
   int a = num;
   if(size == 0)
   {
      return;
   }
   else
   {
      char temp = s.at(s.size() - num - 1);
      s.at(s.size() - num - 1) = s.at(num);
      s.at(num) = temp;
   }
   return reverse(s, (a + 1), (size - 1));
}
void reverse(string &s)
{
   return reverse(s, 0, (s.size() / 2));
}
int main()
{
   string a = "123456789";
   reverse(a);
   return 0;
}