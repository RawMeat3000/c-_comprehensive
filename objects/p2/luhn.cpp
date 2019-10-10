#include "luhn.h"
#include "../util/util.h"

bool luhn::check(unsigned long long card_number)
{
	const long long saved_card_number = card_number;
	unsigned long long mod = 10;
	int total = 0;
	int current_num = 0;
	int card_digits = floor(log10(card_number)) + 1;
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
		card_number = card_number % mod;
	}
	
	if ( total % 10 == 0 && card_digits == 16 )
	{
		cout << "Card number is: " << saved_card_number << " \n\tcard digits: " << card_digits << " \n\tSum " << total << " \n\tVALID" << endl;
		return true;
	}
	else
	{
		cout << "Card number is: " << saved_card_number << " \n\tcard digits: " << card_digits << " \n\tSum " << total << " \n\tINVALID" << endl;
		return false;
	}

}
