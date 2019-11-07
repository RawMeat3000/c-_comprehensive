#include "..\util\util.h"
#include "intmatrix1.h"

void intmatrix1::init(int num_rows, int num_columns, int primer)
{
	_rows = num_rows;
	_columns = num_columns;

	if ( _rows == 0 || _columns == 0 )
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
			_matrix[i] = new int [_columns];
			for ( int j = 0; j < _columns; ++j )
			{
				_matrix[i][j] = primer;
			}
		}
	}
}

void intmatrix1::init(string matrix_str)
{
	bool is_number_prev = false; // track if the last char was a number
	int number = 0;
	int to_int = 48;
	int str_len = matrix_str.length();
	bool break_out = false;
	set_rows_and_columns_from_string(matrix_str);

	// initialize array
	if ( _rows == 0 || _columns == 0 )
	{
		_matrix = new int* [0];
		return;
	}
	else
	{
		_matrix = new int*[_rows];
		for ( int j = 0; j < _rows; j++ )
		{
			_matrix[j] = new int[_columns];
			for ( int k = 0; k < _columns; k++ )
			{
				_matrix[j][k] = -1;
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
			if ( _matrix[r][c] == -1 || is_number_prev )
			{
				if ( is_number_prev )
				{
					number *= 10;
					number += ch - to_int;
					_matrix[r][c] = number;
					break_out = true;
				}
				else
				{
					number = ch - to_int;
					_matrix[r][c] = number;
					is_number_prev = true;
					break_out = true;
				}
			}
		}
	}
}

void intmatrix1::set_rows_and_columns_from_string(string matrix)
{
	bool is_number_prev = false; // track if the last char was a number
	int prev_columns = 0;
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

			if ( _columns != prev_columns )
			{
				if ( prev_columns == 0 )
					prev_columns = _columns;
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
			if ( _columns != prev_columns )
			{
				_columns = 0;
				_rows = 0;
				return;
			}
		}
	}
}

void intmatrix1::print(string message)
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
			cout << _matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void intmatrix1::fini()
{
	for ( int i = 0; i < _rows; i++ )
	{
		delete[] _matrix[i];
	}
	delete[] _matrix;
}

intmatrix1 intmatrix1::add(intmatrix1 m)
{
	intmatrix1 result;

	if ( size_equal(m) && !isEmpty() && !m.isEmpty() )
	{
		result.init(_rows, _columns);
		for ( int i = 0; i < _rows; ++i )
		{
			for ( int j = 0; j < _columns; ++j )
			{
				result._matrix[i][j] = _matrix[i][j] + m._matrix[i][j];
			}
		}
	}
	else
	{
		result.init();
	}

	return result;
}

intmatrix1 intmatrix1::mult(intmatrix1 m)
{
	intmatrix1 result;

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
					result._matrix[i][j] += _matrix[i][k] * m._matrix[k][j];
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

bool intmatrix1::isEqual(intmatrix1 m)
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
			if ( m._matrix[i][j] != _matrix[i][j] )
				is_equal = false;
		}
	}
	return is_equal;
}

bool intmatrix1::isEmpty()
{
	bool is_empty = true;
	for ( int i = 0; i < _rows; ++i )
	{
		for ( int j = 0; j < _columns; ++j )
		{
			if ( _matrix[i][j] != 0 )
			{
				is_empty = false;
			}
		}
	}
	return is_empty;
}

bool intmatrix1::size_equal(intmatrix1 m)
{
	bool is_equal = false;
	if ( m._rows == _rows && m._columns == _columns )
		is_equal = true;
	return is_equal;
}