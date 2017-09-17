#include <iostream>
using namespace std;

int main()
{
  cout << endl;
  /////// PART 1 ///////////////////////////////////////////
  int *int_ptr1;
  int *int_ptr2;
  int int_var = 100; // automatic variable
  
  //point int_ptr1 to int_var
  int_ptr1 = &int_var; // goes out of scope by itself...dont need delete
// pointing a var means get it's address


  //allocate memory from the heap (dynamically) and point int_ptr2 at it
  //store the value 200 in this memory
  int_ptr2 = new int(200);

  cout << "int_var: " << int_var << endl
       << "*int_ptr1: " << *int_ptr1 << endl
       << "*int_ptr2: " << *int_ptr2 << endl
       << endl; // clears buffer-flushes buffer
       // also << flush;

  //add 100 to the values pointed to by both int pointers

  *int_ptr1 = *int_ptr1 + 100;
  *int_ptr2 = *int_ptr2 + 100;
  
  
  cout << "int_var: " << int_var << endl
       << "*int_ptr1: " << *int_ptr1 << endl
       << "*int_ptr2: " << *int_ptr2 << endl
       << endl;

  //delete all dynamically allocated memory in Part 1
 //delete int_ptr1;  can't will cause error cause didn't declare it with new
 // causes free pointer error
 // causes free() error
  delete int_ptr2;

  /////// PART 2 ///////////////////////////////////////////

  //dynamically allocate new memory from the heap for all 3 pointers
  int_ptr1 = new int;
  int_ptr2 = new int;
//int *int_ptr3 = 0; // 0 address never gets used..no access
int *int_ptr3 = new int;
// int *int_ptr3; undefined behavior...
// dangling pointer had address now it doesn't
// if u don't have an address use = 0 so if u accidentally call it
// ull get a seg fault and catch ur mistake
// either store in ur pointer a valid memory or zero
/*
int *int_ptr3; called a dangling/wild pointer
creates undefined behavior might work sometiemes
or might not work at all
if u delete a pointer and it doesn't go out of scope just yet
set to zero....in case 

causes seg fault error
*/

  *int_ptr1 = 400;
  *int_ptr2 = 500;
  *int_ptr3 = 600;

  cout << "int_var: " << int_var << endl
      << "*int_ptr1: " << *int_ptr1 << endl
      << "*int_ptr2: " << *int_ptr2 << endl
      << "*int_ptr3: " << *int_ptr3 << endl
      << endl;

  //point all pointers to the same memory location 
  //  (the one pointed to by int_ptr1)
  //make sure you don't leave allocated memory floating around
  // can do 3 = 2 = 1; little trick..
  delete int_ptr2;
  delete int_ptr3;
  int_ptr2 = int_ptr1; // lose intitial address.....
  int_ptr3 = int_ptr1; // we called new int above causes memry leak
// erase before u ...set to new address no memory leak


  cout << "*int_ptr1: " << *int_ptr1 << endl
      << "*int_ptr2: " << *int_ptr2 << endl
      << "*int_ptr3: " << *int_ptr3 << endl
      << endl;
  
  //delete all remaining dynamically allocated memory in part2
  delete int_ptr1;
//   delete int_ptr2;
//   delete int_ptr3;
/*
// causes double free or corruption
since 1 2 and 3 have same address
don't need to delete over and over 
*/ 

  return 0;
}

// tried deleting iptr1
// seg fault with zero
//tried defelete iptr2 and 3 free corup
// memory leak move delete up