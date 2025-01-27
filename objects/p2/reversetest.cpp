/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: reversetest.cpp

On linux:
g++ reverse.cpp reversetest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
YOU CANNOT CHANGE ANYTHING IN THIS FILE 
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test reverse object 
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "reverse.h"
#include "..\util\util.h"

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
void testbed() {
  reverse1 o;
  cout << "sizeof(unsigned long) = " << sizeof(unsigned long) << endl ;
  const unsigned long a[] = {0,1,10,9,1000,0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFD,0xA7FFFF0,1234567,765432} ;
  const unsigned long e[] =   {0,1,1,9,1,0,0,3927694924,257061671,7654321,234567} ;
  int s = sizeof(a)/sizeof(unsigned long) ;
  for (int i = 0; i < s; ++i) {
    unsigned long n = a[i] ;
    unsigned long b = e[i] ;
    unsigned long a = o.r(n) ;
    cout << "n = " << setw(10) << n  << " a = " << setw(10) << a << " Expected = " << setw(10)<< b <<endl ;
    assert(a == b) ;
  }
  unsigned long first = o.firstFail() ;
  cout << "The first long number for which reverse fails = " << first << endl ;
  unsigned long shouldnotfail = first - 1;
  unsigned long x = o.r(shouldnotfail) ;
  assert(x != 0) ;
  unsigned long shouldfail = first + 1;
  x = o.r(shouldfail) ;
  assert(x == 0) ;
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  testbed() ;
  cout << "All reverse tests passed. You are amazing\n" ;
  return 0 ;
}

//EOF

/*
sizeof(unsigned long) = 4
n =          0 a =          0 Expected =          0
n =          1 a =          1 Expected =          1
n =         10 a =          1 Expected =          1
n =          9 a =          9 Expected =          9
n =       1000 a =          1 Expected =          1
n = 4294967294 a =          0 Expected =          0
n = 4294967295 a =          0 Expected =          0
n = 4294967293 a = 3927694924 Expected = 3927694924
n =  176160752 a =  257061671 Expected =  257061671
n =    1234567 a =    7654321 Expected =    7654321
n =     765432 a =     234567 Expected =     234567
1000000001
1000000002
1000000003
1000000004
1000000005
The first long number for which reverse fails = 1000000005
All reverse tests passed. You are amazing
*/