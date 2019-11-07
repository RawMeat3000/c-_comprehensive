#include "..\util\util.h"
#include "intmatrix2.h"

void intmatrix2::init(int num__rows, int num__columns, int primer)
{
	_rows = num__rows;
	_columns = num__columns;

	if ( _rows == 0 || __columns == 0 )
	{
		_rows = 0;
		_columns = 0;
		_matrix = new int* [0];
	}
	else
	{
		_matrix = new int* [_rows];
		for ( int i = 0; i < _rows; ++i )
		{
			matrix[i] = new int [_columns];
			for ( int j = 0; j < _columns; ++j )
			{
				matrix[i][j] = primer;
			}
		}
	}
}

void intmatrix2::init(string matrix_str)
{
	bool is_number_prev = false; // track if the last char was a number
	int number = 0;
	int to_int = 48;
	int str_len = matrix_str.length();
	bool break_out = false;
	set__rows_and__columns_from_string(matrix_str);

	// initialize array
	if ( _rows == 0 || __columns == 0 )
	{
		_matrix = new int* [0];
		return;
	}
	else
	{
		_matrix = new int*[_rows];
		for ( int j = 0; j < _rows; j++ )
		{
			matrix[j] = new int[_columns];
			for ( int k = 0; k < _columns; k++ )
			{
				matrix[j][k] = -1;
			}
		}
	}

	int r = 0;
	int c = 0;
	for ( int i = 0; i < matrix_str.length(); i++ )
	{
		break_out = false;
		char ch = matrix_str[i];
		if ( ch == '|' )
		{
			r += 1;
			c = 0;
			is_number_prev = false;
			continue;
		}
		if ( ch == ' ' )
		{
			if ( is_number_prev )
			{
				c += 1;
			}
			is_number_prev = false;
			continue;
		}
		if ( ch != '|' && ch != ' ' )
		{
			if ( matrix[r][c] == -1 || is_number_prev )
			{
				if ( is_number_prev )
				{
					number *= 10;
					number += ch - to_int;
					matrix[r][c] = number;
					break_out = true;
				}
				else
				{
					number = ch - to_int;
					matrix[r][c] = number;
					is_number_prev = true;
					break_out = true;
				}
			}
		}
	}
}

void intmatrix2::set__rows_and__columns_from_string(string matrix)
{
	bool is_number_prev = false; // track if the last char was a number
	int prev__columns = 0;
	int m_len = matrix.length();
	_rows = 1;

	if ( !m_len )
	{
		_rows = 0;
		_columns = 0;
		return;
	}

	for ( int i = 0; i < m_len; ++i )
	{
		char c = matrix[i];

		if ( c == '|' )
		{
			if ( is_number_prev )
				_columns += 1;
			is_number_prev = false;

			if ( __columns != prev__columns )
			{
				if ( prev__columns == 0 )
					prev__columns = _columns;
				else
				{
					// mismatched column sizes, bad data
					_columns = 0;
					_rows = 0;
					return;
				}
			}
			_rows += 1;
			_columns = 0;
		}
		if ( c == ' ' )
		{
			if ( is_number_prev )
				_columns += 1;

			is_number_prev = false;
		}
		if ( c != '|' && c != ' ' )
		{
			is_number_prev = true;
			if ( i == m_len - 1 )
				_columns += 1;
		}

		if ( i == m_len - 1)
		{
			if ( __columns != prev__columns )
			{
				_columns = 0;
				_rows = 0;
				return;
			}
		}
	}
}

void intmatrix2::print(string message)
{
	cout << message << endl;
	if ( _rows == 0 )
	{
		cout << "Empty Matrix" << endl << endl;
		return;
	}
	for ( int i = 0; i < _rows; i++ )
	{
		for ( int j = 0; j < _columns; j++ )
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void intmatrix2::fini()
{
	for ( int i = 0; i < _rows; i++ )
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

intmatrix2 intmatrix2::add(intmatrix2 m)
{
	intmatrix2 result;

	if ( size_equal(m) && !isEmpty() && !m.isEmpty() )
	{
		result.init(_rows, _columns);
		for ( int i = 0; i < _rows; ++i )
		{
			for ( int j = 0; j < _columns; ++j )
			{
				result.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
			}
		}
	}
	else
	{
		result.init();
	}

	return result;
}

intmatrix2 intmatrix2::mult(intmatrix2 m)
{
	intmatrix2 result;

	if ( size_equal(m) && !isEmpty() && !m.isEmpty() )
	{
		result.init(_rows, _columns);

		int row_product = 0;
		int column_product = 0;
		int third = 0;
		for ( int i = 0; i < _rows; ++i )
		{
			for ( int j = 0; j < _columns; ++j )
			{
				for ( int k = 0; k < _columns; ++k )
				{
					//cout << i << j << k << endl;
					result.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
				}
			}
		}
	}
	else
	{
		result.init();
	}

	return result;
}

bool intmatrix2::isEqual(intmatrix2 m)
{
	bool is_equal = true;
	for ( int i = 0; i < _rows; ++i )
	{
		for ( int j = 0; j < _columns; ++j )
		{
			if ( m.isEmpty() != isEmpty() )
			{
				is_equal = false;
				continue;
			}
			if ( m.matrix[i][j] != matrix[i][j] )
				is_equal = false;
		}
	}
	return is_equal;
}

bool intmatrix2::isEmpty()
{
	bool is_empty = true;
	for ( int i = 0; i < _rows; ++i )
	{
		for ( int j = 0; j < _columns; ++j )
		{
			if ( matrix[i][j] != 0 )
			{
				is_empty = false;
			}
		}
	}
	return is_empty;
}

bool intmatrix2::size_equal(intmatrix2 m)
{
	bool is_equal = false;
	if ( m._rows == _rows && m._columns == __columns )
		is_equal = true;
	return is_equal;
}