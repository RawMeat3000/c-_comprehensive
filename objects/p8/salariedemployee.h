#include "employee.h"

class salariedemployee : public employee
{
public:
	salariedemployee(const string& fn, const string& ln, const string& ssn, const string& company_name, int salary = 0) :
		employee(fn, ln, ssn), _company_name(company_name), _salary(salary)
	{
		if ( is_output_displayed )
		{
			cout << "salaried employee constructor" << endl;
		}
	}

	virtual ~salariedemployee()
	{
		if ( is_output_displayed )
		{
			cout << "salaried employee destructor" << endl;
		}
	}

	salariedemployee(const salariedemployee& se) :
		employee(se), _company_name(se._company_name), _salary(se._salary)
	{
		if ( is_output_displayed )
		{
			cout << "salaried employee copy constructor" << endl;
		}
	}

	salariedemployee& operator=(const salariedemployee& se)
	{
		if ( &se != this ) 
		{
			employee::operator=(se);
			_company_name = se._company_name;
			_salary = se._salary;
		}
		return *this;
	}

	friend ostream& operator<<(ostream &output, const salariedemployee &se)
	{
		const employee& e = se;
		output << e << endl;
		output << "Company name: " << se._company_name << endl;
		output << "Salary: " << se._salary << endl;
		return output;
	}

private:
	string _company_name;
	int _salary;
};