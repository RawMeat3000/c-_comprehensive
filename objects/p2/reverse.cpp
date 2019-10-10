#include "..\util\util.h"
#include "reverse.h"

unsigned long reverse1::r(unsigned long n)
{
	unsigned long reversed = 0;
	unsigned long reversed_prev = 0;

	while ( n )
	{
		reversed *= 10;
		reversed += n % 10;
		n /= 10;

		reversed_prev *= 5; // this probably fails for some numbers...
		if ( reversed >= reversed_prev )
			reversed_prev = reversed;
		else
			return 0;
	}

	return reversed;
}

unsigned long reverse1::firstFail()
{
	unsigned long n = 1;
	int long_digits = floor(log10(abs(LONG_MAX)));
	// start n at the max number of digits for a type long (10) 
	// since that's the only type of number that should fail
	for ( int i = 0; i < long_digits; i++ )
	{
		n *= 10;
	}

	do
	{
		n += 1;
		cout << n << endl;
	} while ( r(n) );

	return n;
}
