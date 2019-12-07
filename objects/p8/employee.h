#pragma once
#include "..\util\util.h"

class employee
{
public:
	employee(const string& fn, const string& ln, const string& ssn);

	employee(const employee& e);

	virtual ~employee();

	employee& operator=(const employee& e);
	friend ostream& operator<<(ostream &output, const employee &e);

	static bool display();
	static void setShow(bool flag);

private:
	void _release();
	void _copy(const employee& e);

	string _first_name;
	string _last_name;
	string _ssn;

protected:
	static bool is_output_displayed;

};