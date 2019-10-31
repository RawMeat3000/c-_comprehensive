#pragma once


class intmatrix1
{
public:
	void init(int num_rows=0, int num_columns=0, int primer=0);
	void init(string matrix);
	void print(string message);
	void fini();
	intmatrix1 add(intmatrix1 m);
	intmatrix1 mult(intmatrix1 m);
	bool isEqual(intmatrix1 m);
	bool isEmpty();
private:
	int** matrix;
	int rows;
	int columns;
	bool size_equal(intmatrix1 m);
};