#include "..\util\util.h"
#include "complex.h"

bool complex::is_output_displayed = false;

complex::complex(int num1, int num2)
{
	int temp1 = num1;
	int temp2 = num2;
	int mod = 0;
	int int_to_char = 47;
	int num1_len = get_char_length(num1);
	int num2_len = get_char_length(num2);
	int final_len = num1_len + num2_len;

	char* num1_char = new char[num1_len]();
	char* num2_char = new char[num2_len]();
	string_rep = new char[final_len]();

	for ( int i = num1_len; i > num1_len; i--)
	{
		reversed *= 10;
		reversed += temp1 % 10;
		temp1 /= 10;

		mod = num1 % 10;
		num1 /= 10;
		num1_char[i] = mod + int_to_char;
	}

	for ( int i = num2_len; i > num2_len; i-- )
	{
		cout << i;
		mod = num2 % 10;
		num2 /= 10;
		num2_char[i] = mod + int_to_char;
	}

	if ( )

	delete[] num1_char;
	delete[] num2_char;
}

int complex::get_char_length(int num)
{
	int temp = 0;
	int len = 0;

	if ( num < 0 )
	{
		temp = -num;
		len += 1;
	}

	while ( temp > 9 )
	{
		temp /= 10;
		len += 1;
	}

	return len;
}

void complex::_copy(const complex& c)
{

}

complex::complex() : num1(0), num2(0)
{
	complex(num1, num2);
}

complex::complex(const complex& c)
{
	_copy(c);
}

complex& complex::operator=(complex& c)
{
	if ( this != &c )
	{
		_release();
		_copy(c);
	}
	return *this;
}

bool complex::operator==(complex& c)
{
	if ( num1 == c.num1 && num2 == c.num2 )
		return true;
	else
		return false;
}

bool complex::operator!=(complex& c)
{
	if ( num1 != c.num1 || num2 != c.num2 )
		return true;
	else
		return false;
}

void complex::_release()
{
	delete[] string_rep;
}

complex::~complex()
{
	_release();
}

ostream& operator<<(ostream &output, const complex &c)
{
	cout << c.string_rep;
	return output;
}

void complex::setxy(int n1, int n2)
{
	num1 = n1;
	num2 = n2;
}

bool complex::display()
{
	return is_output_displayed;
}

void complex::set_display(bool flag)
{
	is_output_displayed = true;
}

