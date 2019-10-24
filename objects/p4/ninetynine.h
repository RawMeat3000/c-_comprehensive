/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: ninetynine.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ninetynine class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef ninetynine_H
#define ninetynine_H

#include "../util/util.h"

/*----------------------------------------------------------------
Declaration of ninetynine class
-----------------------------------------------------------------*/
class ninetynine{
private:
	void print_(string a, string b, string c, string d, bool plural);
	bool compute_string_(int n, const string** a, const string** b, const string** c, const string** d);
	bool compute_string_(int n, string& a, string& b, string& c, string& d);
	void get_strings(int n, const string** a, const string** b);
	void get_strings(int n, string& a, string& b);
	void stanzaPointer_(int n);
	void stanzaReference_(int n);

	const int MAX = 99 ;
	const char* const of_beer = "of beer";
	const char* const on_the_wall = "on the wall";
	const char* const bottle = "bottle";
	const char const space = ' ';
	const char const ess = 's';
	const char const hyphen = '-';

	const char* const take_one_down = "take one down, pass it around";
	const char* const end_line = ",\n";
	const string const zero_to_nine[10] =
	{
		"",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine",
	};
	const string const teens[10] =
	{
		"ten",
		"eleven",
		"twelve",
		"thirteen",
		"fourteen",
		"fifteen",
		"sixteen",
		"seventeen",
		"eightteen",
		"nineteen"
	};
	const string const tens[10] =
	{
		"",
		"",
		"twenty",
		"thirty",
		"fourty",
		"fifty",
		"sixty",
		"seventy",
		"eighty",
		"ninety"
	};
	const string end_of_song = "We're out of beer!";
public:
  //NOTHING CAN BE ADDED IN PUBLIC
  void run();
};

#endif

