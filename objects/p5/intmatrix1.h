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
	int** _matrix;
	int _rows = 0;
	int _columns = 0;
	bool size_equal(intmatrix1 m);
	void set_rows_and_columns_from_string(string matrix);
};