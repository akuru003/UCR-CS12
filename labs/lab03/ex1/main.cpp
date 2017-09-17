//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 3
///
/// @author Test Student [akuru003@ucr.edu]
/// @date January 17, 2015
//  ================== END ASSESSMENT HEADER ===============
#include <iostream> 
using namespace std;

const int M  = 2;
const int N = 3;

void matrixAdd(const int a[][N], const int b[][N], int sum[][N])
{
   for(int r = 0; r < M; r++)
   {
      for(int c = 0; c < N; c++)
      {
         sum[r][c] = a[r][c] + b[r][c];
      }
   }
   cout << "Res:" << endl;
   for(int r = 0; r < M; r++)
   {
      for(int c = 0; c < N; c++)
      {
        cout << sum[r][c] << ' ';
      }
      cout << endl;
   }
}
int main()
{
    int a[M][N];
    int b[M][N];
    int c[M][N];
    int input;
    cout << "Enter Matrix A: ";
    for(int r = 0; r < M; r++)
    {
      for(int c = 0; c < N; c++)
      {
            cin >> input;
            a[r][c] = input;
      }
    }
    cout << endl;
    cout << "Enter Matrix B: ";
    for(int r = 0; r < M; r++)
    {
      for(int c = 0; c < N; c++)
      {
            cin >> input;
            b[r][c] = input;
      }
    }
    matrixAdd(a,b,c);
    return 0;
}

