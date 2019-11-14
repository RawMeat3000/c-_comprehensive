#pragma once


class intmatrix2
{
public:

	intmatrix2(int num_rows, int num_columns, int primer);
	intmatrix2(int num_rows, int num_columns);
	intmatrix2();

	intmatrix2(const string matrix);

	intmatrix2(const intmatrix2& imtrx);

	~intmatrix2();

	intmatrix2& add(intmatrix2 &m);
	intmatrix2& operator+(intmatrix2& m);

	intmatrix2& mult(intmatrix2 &m);
	intmatrix2& operator*(intmatrix2& m);

	intmatrix2& operator=(intmatrix2& m);

	friend ostream& operator<<(ostream &output, const intmatrix2 &m);

	bool isEqual(intmatrix2 &m);
	bool isEmpty();
private:
	int** _matrix;
	int _rows = 0;
	int _columns = 0;
	bool _size_equal(const intmatrix2 &m);
	void _set_rows_and_columns_from_string(const string matrix);
	void _release();
	void _copy(const intmatrix2& imtrx);
};