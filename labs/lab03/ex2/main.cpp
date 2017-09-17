//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 3
///
/// @author Test Student [akuru003@ucr.edu]
/// @date January 20, 2015
//  ================== END ASSESSMENT HEADER ===============
#include <iostream> 
using namespace std;

const int Q = 2; 
const int R = 3;
const int S = 3;

void matrixMult(const int a[][R], const int b[][S], int product[][S])
{
   int sum = 0;
   for(int r = 0; r < Q; r++) 
   {
      for(int c = 0; c < S; c++)
      {
         sum = 0;
         for(int in = 0; in < R; in++)
	      {
	         sum += a[r][in] * b[in][c];
   	   }
         product[r][c] = sum;
      }  
   }         
}
int main()
{
   int a[Q][R] = {}; // 2 3
   int b[R][S] = {}; // 3 3
   int d[Q][S] = {}; // 2 3
   cout << "Enter Matrix A(size 2x3): ";
   for(int r = 0; r < Q; r++) // 2 
   {
      for(int c = 0; c < R; c++)  // 3
      {
         cin >> a[r][c];
      }
   }
   cout << endl;
   cout << "Enter Matrix B(size 3x3): ";
   for(int r = 0; r < R; r++) // 3
   {
      for(int c = 0; c < S; c++) // 3
      {
         cin >> b[r][c];
      }
   }
   cout << endl;
   matrixMult(a,b,d);
   cout << "Res:" << endl;
   for(int r = 0; r < Q; r++)
   {
      for(int c = 0; c < S; c++)
      {
         cout << d[r][c]  << ' ';
      }
      cout << endl;
   }
   return 0;
}