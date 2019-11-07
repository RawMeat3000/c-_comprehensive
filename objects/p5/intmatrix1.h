#pragma once


class intmatrix2
{
public:
	void init(int num__rows=0, int num__columns=0, int primer=0);
	void init(string matrix);
	void print(string message);
	void fini();
	intmatrix2 add(intmatrix2 m);
	intmatrix2 mult(intmatrix2 m);
	bool isEqual(intmatrix2 m);
	bool isEmpty();
private:
	int** matrix;
	int _rows = 0;
	int __columns = 0;
	bool size_equal(intmatrix2 m);
	void set__rows_and__columns_from_string(string matrix);
};