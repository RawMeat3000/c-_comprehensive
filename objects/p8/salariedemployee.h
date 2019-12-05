#include "employee.h"

class salariedemployee : public employee
{
public:
	salariedemployee(string fn, string ln, string ssn, string company_name, int salary) :
		employee(fn, ln, ssn), _company_name(company_name), _salary(salary)
	{
		cout << "salaried employee constructor" << endl;
	}

	salariedemployee(const salariedemployee& se) :
		employee(se), _company_name(se._company_name), _salary(se._salary)
	{
		cout << "salaried employee copy constructor" << endl;
	}

	salariedemployee& operator=(const salariedemployee& se)
	{
		if ( &se != this ) 
		{
			cout << "salariedemployee = operator " << se._company_name << endl;
			employee::operator=(se);
			_company_name = se._company_name;
			_salary = se._salary;
		}
		return *this;
	}

private:
	string _company_name;
	int _salary;
};