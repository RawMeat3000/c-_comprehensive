#pragma once


class intmatrix1
{
public:
	void init(const int num_rows=0, const int num_columns=0, const int primer=0);
	void print(string message);
	void fini();
	void add(int* matrix1, int* matrix2);
	void mult(int* matrix1, int* matrix2);
	void isEqual(int* matrix1, int* matrix2);
private:
	int** matrix;
	bool size_equal(int* matrix1, int* matrix2);
};