
#include "p1.h";
#include "../util/util.h"

void p1::print_usa()
{
	cout << "print_usa\n";

	// maybe bitshift this?
	int usa_code[] = {  0,0,0,0,0,0,0,0,0,0,1,0,
						0,0,1,1,1,1,1,1,1,1,1,0,
						0,1,1,0,0,0,0,0,0,0,1,0,
						0,1,0,0,0,0,0,0,0,0,0,0,
						0,1,0,0,0,0,0,0,0,0,0,0,
						0,1,0,0,0,0,0,0,0,0,0,0,
						0,1,0,0,0,0,0,0,0,0,1,0, 
						0,1,1,1,1,1,1,1,1,1,1,0, 
						0,0,0,0,0,0,0,0,0,0,1,0, 
						0,0,0,0,0,0,0,0,0,0,0,0, 
						0,0,0,0,0,0,0,0,0,0,0,0, 
						0,1,1,1,0,0,0,1,1,1,0,0, 
						0,0,1,0,0,0,1,0,0,0,1,0, 
						0,1,0,0,0,0,1,0,0,0,1,0, 
						0,1,0,0,0,0,1,0,0,0,1,0,
						0,1,0,0,0,1,0,0,0,0,1,0,
						0,1,0,0,0,1,0,0,0,1,0,0,
						0,0,1,1,1,0,0,0,1,1,1,0,
						0,0,0,0,0,0,0,0,0,0,0,0,
						0,1,0,0,0,0,0,0,0,0,0,0,
						0,1,1,1,0,0,0,0,0,0,0,0,
						0,1,0,0,1,1,1,0,0,0,1,0,
						0,0,0,0,1,0,0,1,1,0,1,0,
						0,0,0,0,1,0,0,0,0,1,1,0,
						0,0,0,0,1,0,0,1,1,0,0,0,
						0,1,0,0,1,1,1,0,0,0,0,0,
						0,1,1,1,0,0,0,0,0,0,0,0,
						0,1,0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,0,0 };

	int num_columns = 12;
	int num_rows = (sizeof( usa_code ) / sizeof( int )) / num_columns;
	int usa_index = 0;
	int usa_a_ok = 0;

	int first = 1;
	for ( int i = first; i < num_columns + first; i++ )
	{
		for ( int j = first; j < num_rows + first; j++ )
		{
			usa_index = num_columns * j - i;
			usa_a_ok = usa_code[usa_index];

			if ( usa_a_ok )
				cout << "X" ;
			else
				cout << " " ;
		}
		cout << "\n";
	}
}

void p1::print_n_n2_n3()
{
	cout << "print_n_n2_n3\n";

	int n = 1;
	int n_iters = 9;
	cout << "n" << setw(5) << "n^2" << setw(5) << "n^3\n";
	for ( int i = 0; i < n_iters; i++ )
	{
		cout << pow(n, 1) << setw( 5 ) << pow(n, 2) << setw( 5 ) << pow(n, 3) << "\n";
		n++;
	}
}

void p1::a_power_b()
{
	cout << "a_power_b\n";

	int a = 1;
	int b = 2;
	int num_iters = 7;
	long a_pow_b;
	cout << "a" << setw(3) << "b" << setw( 10 ) << "a^b\n";
	for ( int i = 0; i < num_iters; i++ )
	{
		a_pow_b = pow(a, b);
		cout << a << setw(3) << b << setw(10) << a_pow_b << "\n";
		a++;
		b++;
	}
}

void p1::two_power_n()
{
	cout << "two_power_n\n";

	int n = 0;
	int num_iters = 21;
	long two_pow_n;
	cout << "n" << setw(10) << "2^n\n";
	for ( int i = 0; i < num_iters; i++ )
	{
		two_pow_n = pow(2, n);
		cout << n << setw(10) << two_pow_n << "\n";
		n++;
	}
}

int p1::check_a_input(int start, int end)
{
	if ( start >= end )
	{
		cout << "End must be more than start\n";
		return 1;
	}
	if ( start < 0 )
	{
		cout << "Start must be at least 0\n";
		return 2;
	}
	if ( end > 9 )
	{
		cout << "End must be less than 9\n";
		return 3;
	}

	return 0;
}

void p1::a1(int start, int end)
{
	cout << "a1\n";

	int num_prints = end - start + 2;

	if ( check_a_input(start, end) == 0 )
	{
		for ( int i = 0; i < num_prints; i++ )
		{
			for ( int j = start; j < start + i; j++ )
			{
				cout << " ";
				cout << j;
			}
			cout << "\n";
		}
	}
}

void p1::a2(int start, int end)
{
	cout << "a2\n";

	int num_prints = end - start + 2;

	if ( check_a_input(start, end) == 0 )
	{
		for ( int i = 0; i < num_prints; i++ )
		{
			for ( int j = num_prints - 1; j > 0; j-- )
			{
				cout << " ";
				if ( i < j )
					cout << " ";
				else
					cout << j;
			}
			cout << "\n";
		}
	}
}

void p1::a3(int start, int end)
{
	cout << "a3\n";

	int num_prints = end - start + 2;

	if ( check_a_input(start, end) == 0 )
	{
		for ( int i = 0; i < num_prints; i++ )
		{
			for ( int j = num_prints - 1; j > 0; j-- )
			{
				cout << " ";
				if ( i < j )
					cout << end - j + 1;
				else
					cout << " ";
			}
			cout << "\n";
		}
	}
}

void p1::a4(int start, int end)
{
	cout << "a4\n";

	int num_prints = end - start + 2;

	if ( check_a_input(start, end) == 0 )
	{
		for ( int i = num_prints; i > 0; i-- )
		{
			for ( int j = num_prints - 1; j > 0; j-- )
			{
				cout << " ";
				if ( i > j )
					cout << start + i - j - 1;
				else
					cout << " ";
			}
			cout << "\n";
		}
	}
}

void p1::riceOnChessBoard(int num_squares)
{
	cout << "riceOnChessBoard\n";

	int square_num = 1;
	unsigned long long total_rice = 1;
	for ( int i = 0; i < num_squares; i++ )
	{
		cout << "Rice on Square" << square_num << " = " << total_rice << "\n";
		square_num++;
		total_rice += total_rice;
	}

	cout << "Total rice = " << total_rice - 1 << "\n";
	cout << "Total rice must be = 18446744073709551615\n";

}