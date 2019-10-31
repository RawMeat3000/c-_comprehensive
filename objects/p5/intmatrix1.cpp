#include "..\util\util.h"
#include "intmatrix1.h"

void intmatrix1::init(int num_rows, int num_columns, int primer)
{
	rows = num_rows;
	columns = num_columns;

	if ( rows == 0 || columns == 0 )
	{
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
void intmatrix1::init(string matrix)
{

}
void intmatrix1::print(string message)
{

}
void intmatrix1::fini()
{
	for ( int i = 0; i < rows; ++i )
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
intmatrix1 intmatrix1::add(intmatrix1 m)
{
	intmatrix1 result = m;
	for ( int i = 0; i < rows; ++i )
	{
		for ( int j = 0; j < columns; ++j )
		{
		}
	}
	return result;
}
intmatrix1 intmatrix1::mult(intmatrix1 m)
{
	intmatrix1 result = m;
	for ( int i = 0; i < rows; ++i )
	{
		for ( int j = 0; j < columns; ++j )
		{

		}
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
			if ( m.matrix[i][j] != matrix[i][j] )
			{
				is_equal = false;
			}
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
	for ( int i = 0; i < rows; ++i )
	{
		for ( int j = 0; j < columns; ++j )
		{
		}
	}
	return is_equal;
}