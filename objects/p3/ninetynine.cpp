#include "../util/util.h"
#include "ninetynine.h"


void print_bottles(int num_bottles, bool wall, bool second_line)
{
	const char* const of_beer = "of beer";
	const char* const on_the_wall = "on the wall";
	const char* const bottle = "bottle";
	const char const space = ' ';
	const char const ess = 's';
	const char const hyphen = '-';

	const char* const take_one_down = "take one down, pass it around";
	const char* const end_line = ",\n";
	const char* const zero_to_nine[] = {
		"zero",
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
	const char* const teens[] =
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
	const char* const tens[] =
	{
		NULL,
		NULL,
		"twenty",
		"thirty",
		"fourty",
		"fifty",
		"sixty",
		"seventy",
		"eighty",
		"ninety"
	};

	int tens_place = 0;
	int ones_place = 0;

	tens_place = (num_bottles / 10);
	ones_place = num_bottles % 10;

	if ( num_bottles > 19 )
	{
		cout << tens[tens_place];
		if ( ones_place )
		{
			cout << hyphen;
			cout << zero_to_nine[ones_place];
		}
	}
	else if ( 9 < num_bottles && num_bottles < 20 )
	{
		cout << teens[ones_place];
	}
	else if ( 0 < num_bottles && num_bottles < 10 )
	{
		cout << zero_to_nine[ones_place];
	}
	else if ( num_bottles == 0 )
	{
		cout << "..." << endl;
		cout << "..." << endl;
		cout << "We're out of beer!" << endl;
		return;
	}

	cout << space << bottle;

	if ( num_bottles > 1 )
		cout << ess;

	cout << space << of_beer;

	if ( !second_line )
		cout << space << on_the_wall;

	cout << end_line;

	if ( second_line )
		cout << take_one_down << end_line;
}

void ninetynine::run()
{
	int num_bottles = 99;

	for ( ; num_bottles > 0; )
	{
		print_bottles(num_bottles, true, false);
		print_bottles(num_bottles, false, true);

		// minus for verse 2
		num_bottles--;		

		print_bottles(num_bottles, true, false);

		cout << endl;
	}
}

