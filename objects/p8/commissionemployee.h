#include "employee.h"

class commissionemployee : public employee
{
public:
	commissionemployee(string fn, string ln, string ssn, string company_name, int salary) :
		employee(fn, ln, ssn), _company_name(company_name), _salary(salary)
	{
		cout << "commission employee constructor" << endl;
	}

	commissionemployee(const commissionemployee& ce) :
		employee(ce), _company_name(ce._company_name), _salary(ce._salary)
	{
		cout << "commission employee copy constructor" << endl;
	}

	commissionemployee& operator=(const commissionemployee& ce)
	{
		if ( &ce != this )
		{
			cout << "salariedemployee = operator " << ce._company_name << endl;
			employee::operator=(ce);
			_company_name = ce._company_name;
			_salary = ce._salary;
		}
		return *this;
	}

private:
	string _company_name;
	int _salary;
};