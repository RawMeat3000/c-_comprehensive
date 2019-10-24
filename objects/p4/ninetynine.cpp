/*----------------------------------------------------------------
Copyright (c) 2019 Author: Jagadeesh Vasudevamurthy
file: ninetynine.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ninetynine class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ninetynine.h"
#include "..\util\util.h"

/*----------------------------------------------------------------
Ninety nine bottles of beer on the wall,
Ninety nine bottles of beer,
Take one down, pass it around,
Ninety eight bottles of beer on the wall.

One bottle of beer on the wall,
One bottle of beer,
Take one down, pass it around,
Zero bottle of beer on the wall.
(91)
a = Ninety   
b = one   
bool true
(90)
c = Ninety   
d = ""
bool true 

YOU GET a,b, bool
YOU GER c,d, bool

PRINT ONE STANZA HERE
----------------------------------------------------------------*/
void ninetynine::print_(const string a, const string b, const string c, const string d, bool plural) {

	// line 1
	if ( !a.empty() )
		cout << a;
	if ( !a.empty() && !b.empty() )
		cout << hyphen;
	if ( !b.empty() )
		cout << b;
	cout << space << bottle;
	if ( plural )
		cout << ess;
	cout << space << of_beer << space << on_the_wall << end_line;

	// line 2
	if ( !a.empty() )
		cout << a;
	if ( !a.empty() && !b.empty() )
		cout << hyphen;
	if ( !b.empty() )
		cout << b;
	cout << space << bottle;
	if ( plural )
		cout << ess;
	cout << space << of_beer << end_line;

	// line 3
	cout << take_one_down << end_line;

	// line 4
	if ( c == end_of_song )
	{
		cout << c;
		return;
	}
	if ( !c.empty() )
		cout << c;
	if ( !c.empty() && !d.empty() )
		cout << hyphen;
	if ( !d.empty() )
		cout << d;
	cout << space << bottle;
	if ( plural )
		cout << ess;
	cout << space << of_beer << space << on_the_wall << end_line << endl;

}

/*----------------------------------------------------------------
NOTHING CAN BE CHANGED BELOW
*----------------------------------------------------------------*/
void ninetynine::run() {
	cout << "REFERENCE BASED SONG\n" ;
	for (int i = MAX; i > 0; --i) {
	stanzaReference_(i);
	}

	cout << endl;
	cout << endl;
	cout << "===============================================================================" << endl;;
	cout << "===============================================================================" << endl;;
	cout << "END OF FIRST SONG" << endl;;
	cout << "===============================================================================" << endl;;
	cout << "===============================================================================" << endl;;
	cout << endl;
	cout << endl;

	cout << "POINTER BASED SONG\n" ;
	for (int i = MAX; i > 0; --i) {
	stanzaPointer_(i) ;
	}
}

//EOF


