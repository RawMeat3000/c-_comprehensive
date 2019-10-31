#include "..\util\util.h"
#include "intmatrix1.h"

void intmatrix1::init(const int num_rows, const int num_columns, const int primer)
{
    matrix = new int*[num_rows];
	for ( int i = 0; i < num_rows; i++ )
	{
		*matrix = new int[num_columns];
		for ( int j = 0; j < num_columns; j++ )
		{
			matrix[i][j] = primer;
		}
	}
	return;
}
void intmatrix1::print(string message)
{

}
void intmatrix1::fini()
{

}
void intmatrix1::add(int* matrix1, int* matrix2)
{

}
void intmatrix1::mult(int* matrix1, int* matrix2)
{

}
void intmatrix1::isEqual(int* matrix1, int* matrix2)
{

}

bool intmatrix1::size_equal(int* matrix1, int* matrix2)
{

}