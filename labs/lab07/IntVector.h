/// @author <Abraham Kuruvila> [akuru003@ucr.edu]
/// @date <2/14/2015>
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
#ifndef INTVECTOR_H
#define INTVECTOR_H

class IntVector
{
   private:
   unsigned sz;
   unsigned cap;
   int* data;
   public:
   IntVector();
   IntVector(unsigned size);
   IntVector(unsigned size, int value);
   unsigned size() const;
   unsigned capacity() const;
   bool empty() const;
   const int & at(unsigned index) const;
};
#endif