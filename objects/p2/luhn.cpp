#include "luhn.h"
#include "../util/util.h"

bool luhn::check(unsigned long long card_number)
{
	unsigned long long mod = 10;
	int current_num = 0;
	int long_long_digits = floor(log10(LLONG_MAX));
	cout << card_number << endl;
	for ( int i = 0; i < long_long_digits; )
	{
		mod = card_number % mod;

		card_number -= mod;
		cout << "Card num " << card_number << endl;
		current_num = card_number / (mod / 10);
		cout << "Current num " << mod << endl;

		i += 2;
		mod = pow(10, i);
		cout << "Mod" << mod << endl;
	}

	return false;
}
