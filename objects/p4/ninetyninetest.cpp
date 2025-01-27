/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: ninetyninetest.cpp

On linux:
g++ ninetynine.cpp ninetyninetest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test ninetynine object
NOTHING CAN BE CHANKGED IN THIS FILE
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ninetynine.h"

/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
void testbed() {
#ifdef _WIN32
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  ninetynine a;
  a.run();
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  testbed();
  return 0;
}

//EOF

