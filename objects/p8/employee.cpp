#include "..\util\util.h"
#include "employee.h"

bool employee::is_output_displayed = true;

employee::employee(string fn, string ln, string ssn) : _first_name(fn), _last_name(ln), _ssn(ssn)
{
	if ( is_output_displayed )
	{
		cout << "employee constructor" << endl;
	}
}

void employee::_copy(const employee& e)
{

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

bool employee::operator!=(employee& e)
{
	//TODO
	return false;
}

void employee::_release()
{
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

