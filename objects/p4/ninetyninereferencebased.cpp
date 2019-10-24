/*----------------------------------------------------------------
Copyright (c) 2019 Author: Jagadeesh Vasudevamurthy
file: ninetyninereferencebased
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
compute strings. reference based
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ninetynine.h"

/*----------------------------------------------------------------
compute strings object based
YOU GET 
n
and you have to generate a and b

if n = 90
a = string Ninety
b = empty string
bool is true

if n = 1
a = string one
b = empty string
bool is false
----------------------------------------------------------------*/
bool ninetynine::compute_string_(int n, string& a, string& b, string& c, string& d) {
	bool plural = true;
	if ( n == 1 )
		plural = false;

	get_strings(n, a, b);
	if ( n > 0 )
		get_strings(n - 1, c, d);

	return plural;
}

void ninetynine::get_strings(int n, string& a, string& b)
{
	int tens_place = n / 10;
	int ones_place = n % 10;

	if ( n > 19 )
	{
		a = tens[tens_place];
		b = zero_to_nine[ones_place];
	}
	else if ( n > 9 )
	{
		a = teens[ones_place];
		b = zero_to_nine[0]; // empty
	}
	else if ( n > 1 )
	{
		a = tens[0]; // empty
		b = zero_to_nine[ones_place];
	}
	else if ( n == 1 )
	{
		a = tens[0]; // empty
		b = zero_to_nine[ones_place];
	}
	else
	{
		a = end_of_song;
		b = zero_to_nine[0]; // empty
	}
}

/*----------------------------------------------------------------
compute strings using Objects
*----------------------------------------------------------------*/
void ninetynine::stanzaReference_(int n) {
	string a{} ;//null string
	string b{} ;
	string c{} ;
	string d{} ;

	bool plural = compute_string_(n, a, b, c, d);
 
	print_(a, b, c, d, plural);
}

//EOF


