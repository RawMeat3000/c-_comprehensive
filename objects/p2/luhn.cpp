#include "luhn.h"
#include "../util/util.h"

bool luhn::check(unsigned long long card_number)
{
	unsigned long long mod = 10;
	int total = 0;
	int current_num = 0;
	int card_digits = floor(log10(card_number)) + 1;
	cout << card_number << endl;
	for ( int i = 1; i <= card_digits; i++ )
	{
		mod = pow(10, (card_digits - i));
		if ( i % 2 == 1 )
		{
			current_num = card_number / mod;
			current_num *= 2;
			if ( current_num >= 10 )
			{
				current_num = 1 + (current_num % 10);
			}
		}
		else
		{
			current_num = card_number / mod;
		}
		total += current_num;
		cout << "Current total " << total << endl;
		card_number = card_number % mod;
	}
	cout << "TOTAL IS " << total << endl;
	
	if ( total % 10 == 0 )
		return true;
	else
		return false;
}
