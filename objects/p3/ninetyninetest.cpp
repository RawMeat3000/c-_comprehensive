/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: ninetyninetest.cpp

On linux:
g++ ninetynine.cpp ninetyninetest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test ninetynine object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "../util/util.h"
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

