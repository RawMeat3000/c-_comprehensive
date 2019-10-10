/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: luhntest.cpp

On linux:
g++ luhn.cpp luhntest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test luhn object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "luhn.h"
#include "../util/util.h"

/*----------------------------------------------------------------
https://www.paypalobjects.com/en_US/vhelp/paypalmanager_help/credit_card_numbers.htm
-----------------------------------------------------------------*/
void test1() {
  const long long list[] = { 378282246310005, 371449635398431, 378734493671000, 5610591081018250, 30569309025904, 38520000023237, 6011111111111117, 6011000990139424, 3530111333300000, 5105105105105100, 4111111111111111, 4012888888881881 };
  const bool ans[] = {0,0,0,1,0,0,1,1,1,1,1,1} ;
  int s = sizeof(list) / sizeof(long long);
  int a = sizeof(ans)/sizeof(bool) ;
  assert(s == a) ;
  for (int i = 0; i < s; ++i) {
    luhn a;
    long long j = list[i];
    assert(a.check(j) == ans[i]) ;
  }
}

/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
void testbed() {
  luhn a;
  assert(a.check(4012888888881881));
  assert(a.check(378282246310005) == false);
  assert(a.check(4012888888881880) == false);
  assert(a.check(4222222222222) == false);
  test1();
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  testbed();
  return 0;
}

//EOF

/*
Card number is: 4012888888881881
card digits: 16
Sum 90
VALID
Card number is: 378282246310005
card digits: 15
Sum 48
INVALID
Card number is: 4012888888881880
card digits: 16
Sum 89
INVALID
Card number is: 4222222222222
card digits: 13
Sum 44
INVALID
Card number is: 378282246310005
card digits: 15
Sum 48
INVALID
Card number is: 371449635398431
card digits: 15
Sum 76
INVALID
Card number is: 378734493671000
card digits: 15
Sum 72
INVALID
Card number is: 5610591081018250
card digits: 16
Sum 40
VALID
Card number is: 30569309025904
card digits: 14
Sum 50
INVALID
Card number is: 38520000023237
card digits: 14
Sum 40
INVALID
Card number is: 6011111111111117
card digits: 16
Sum 30
VALID
Card number is: 6011000990139424
card digits: 16
Sum 50
VALID
Card number is: 3530111333300000
card digits: 16
Sum 40
VALID
Card number is: 5105105105105100
card digits: 16
Sum 20
VALID
Card number is: 4111111111111111
card digits: 16
Sum 30
VALID
Card number is: 4012888888881881
card digits: 16
Sum 90
VALID
*/