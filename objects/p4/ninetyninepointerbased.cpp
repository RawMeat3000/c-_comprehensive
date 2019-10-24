/*----------------------------------------------------------------
Copyright (c) 2019 Author: Jagadeesh Vasudevamurthy
file:ninetyninepointerbased.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
compute string- pointer version
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ninetynine.h"
#include "..\util\util.h"


/*----------------------------------------------------------------
compute strings pointer based

YOU GET 
n
and you have to generate pointer to string a and pointer to string b

if n = 90
a points to string ninety
b points to empty string
bool is true

if n = 1
a points to string 0ne
b points to empty string
bool is false
----------------------------------------------------------------*/
bool ninetynine::compute_string_(int n, const string** a, const string** b, const string** c, const string** d) {
	bool plural = true;
	if ( n == 1 )
		plural = false;

	get_strings(n, a, b);
	if ( n > 0 )
		get_strings(n - 1, c, d);

	return plural;
}

void ninetynine::get_strings(int n, const string **a, const string** b)
{
	int tens_place = n / 10;
	int ones_place = n % 10;

	if ( n > 19 )
	{
		*a = &tens[tens_place];
		*b = &zero_to_nine[ones_place];
	}
	else if ( n > 9 )
	{
		*a = &teens[ones_place];
		*b = &zero_to_nine[0]; // empty
	}
	else if ( n > 1 )
	{
		*a = &tens[0]; // empty
		*b = &zero_to_nine[ones_place];
	}
	else if ( n == 1 )
	{
		*a = &tens[0]; // empty
		*b = &zero_to_nine[ones_place];
	}
	else
	{
		*a = &end_of_song;
		*b = &zero_to_nine[0]; // empty
	}
}

/*----------------------------------------------------------------
compute strings using Pointers
*----------------------------------------------------------------*/
void ninetynine::stanzaPointer_(int n) {
	const string* a = nullptr ;
	const string* b = nullptr ;
	const string* c = nullptr ;
	const string* d = nullptr ;

	bool plural = compute_string_(n, &a, &b, &c, &d);
	print_(*a, *b, *c, *d, plural);
}


//EOF


