#include "..\util\util.h"
#include "intmatrix1.h"

void intmatrix1::init(int num_rows, int num_columns, int primer)
{
	rows = num_rows;
	columns = num_columns;

	if ( rows == 0 || columns == 0 )
	{
		rows = 0;
		columns = 0;
		matrix = new int* [0];
	}
	else
	{
		matrix = new int* [rows];
		for ( int i = 0; i < rows; ++i )
		{
			matrix[i] = new int [columns];
			for ( int j = 0; j < columns; ++j )
			{
				matrix[i][j] = primer;
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
	if ( rows == 0 || columns == 0 )
	{
		matrix = new int* [0];
		return;
	}
	else
	{
		matrix = new int*[rows];
		for ( int j = 0; j < rows; j++ )
		{
			matrix[j] = new int[columns];
			for ( int k = 0; k < columns; k++ )
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

void intmatrix1::set_rows_and_columns_from_string(string matrix)
{
	bool is_number_prev = false; // track if the last char was a number
	int prev_columns = 0;
	int m_len = matrix.length();
	rows = 1;

	if ( !m_len )
	{
		rows = 0;
		columns = 0;
		return;
	}

	for ( int i = 0; i < m_len; ++i )
	{
		char c = matrix[i];

		if ( c == '|' )
		{
			if ( is_number_prev )
				columns += 1;
			is_number_prev = false;

			if ( columns != prev_columns )
			{
				if ( prev_columns == 0 )
					prev_columns = columns;
				else
				{
					// mismatched column sizes, bad data
					columns = 0;
					rows = 0;
					return;
				}
			}
			rows += 1;
			columns = 0;
		}
		if ( c == ' ' )
		{
			if ( is_number_prev )
				columns += 1;

			is_number_prev = false;
		}
		if ( c != '|' && c != ' ' )
		{
			is_number_prev = true;
			if ( i == m_len - 1 )
				columns += 1;
		}

		if ( i == m_len - 1)
		{
			if ( columns != prev_columns )
			{
				columns = 0;
				rows = 0;
				return;
			}
		}
	}
}

void intmatrix1::print(string message)
{
	cout << message << endl;
	if ( rows == 0 )
	{
		cout << "Empty Matrix" << endl << endl;
		return;
	}
	for ( int i = 0; i < rows; i++ )
	{
		for ( int j = 0; j < columns; j++ )
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void intmatrix1::fini()
{
	for ( int i = 0; i < rows; i++ )
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

intmatrix1 intmatrix1::add(intmatrix1 m)
{
	intmatrix1 result;

	if ( size_equal(m) && !isEmpty() && !m.isEmpty() )
	{
		result.init(rows, columns);
		for ( int i = 0; i < rows; ++i )
		{
			for ( int j = 0; j < columns; ++j )
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

intmatrix1 intmatrix1::mult(intmatrix1 m)
{
	intmatrix1 result;

	if ( size_equal(m) && !isEmpty() && !m.isEmpty() )
	{
		result.init(rows, columns);
		for ( int i = 0; i < rows; ++i )
		{
			for ( int j = 0; j < columns; ++j )
			{
				result.matrix[i][j] = matrix[i][j] * m.matrix[i][j];
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
	for ( int i = 0; i < rows; ++i )
	{
		for ( int j = 0; j < columns; ++j )
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

bool intmatrix1::isEmpty()
{
	bool is_empty = true;
	for ( int i = 0; i < rows; ++i )
	{
		for ( int j = 0; j < columns; ++j )
		{
			if ( matrix[i][j] != 0 )
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
	if ( m.rows == rows && m.columns == columns )
		is_equal = true;
	return is_equal;
}