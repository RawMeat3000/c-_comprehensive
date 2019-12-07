#include "..\util\util.h"
#include "employee.h"

bool employee::is_output_displayed = true;

employee::employee(const string& fn, const string& ln, const string& ssn) : _first_name(fn), _last_name(ln), _ssn(ssn)
{
	_first_name = fn;
	_last_name = ln;
	_ssn = ssn;

	if ( is_output_displayed )
	{
		cout << "employee constructor" << endl;
	}
}

void employee::_copy(const employee& e)
{
	_first_name = e._first_name;
	_last_name = e._last_name;
	_ssn = e._ssn;
}

employee::employee(const employee& e) : _first_name(e._first_name), _last_name(e._last_name), _ssn(e._ssn)
{
	if ( is_output_displayed )
	{
		cout << "employee copy constructor" << endl;
	}
	_copy(e);
}

employee& employee::operator=(const employee& e)
{
	if ( this != &e )
	{
		_release();
		_copy(e);
	}
	return *this;
}

void employee::_release()
{
	// nothing to release...
}

employee::~employee()
{
	if ( is_output_displayed )
	{
		cout << "employee destructor" << endl;
	}
	_release();
}

ostream& operator<<(ostream &output, const employee &e)
{
	output << "First name: " << e._first_name << endl;
	output << "Last name: " << e._last_name << endl;
	output << "SSN: " << e._ssn << endl;
	return output;
}

bool employee::display()
{
	return is_output_displayed;
}

void employee::setShow(bool flag)
{
	is_output_displayed = true;
}

