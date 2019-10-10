#include "..\util\util.h"
#include "reverse.h"

unsigned long reverse1::r(unsigned long n)
{
	unsigned long reversed = 0;
	//cout << firstFail() << endl;
	//if ( firstFail() > n )
	//{
	//	unsigned long long reversed = 0;
	//}

	while ( n != 0 )
	{  
		reversed *= 10;
		reversed += n % 10;
		n /= 10;
	}

	return reversed;
}

unsigned long reverse1::firstFail()
{
	/*
	uLong
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	*/
	unsigned long n = 0;
	//int n_bits = sizeof(n) * 8;
	//for ( int i = 0; i < n_bits; i++ )
	//{
	//	n = n << 1;
	//	cout << "N is " << n - 1 << endl;
	//}
	n -= 1; // 
	n /= 2;
	n += 1;

	//cout << r(n) << endl;

	return n;
}
