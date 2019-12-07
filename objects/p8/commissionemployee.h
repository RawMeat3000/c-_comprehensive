#include "employee.h"

class commissionemployee : public employee
{
public:
	commissionemployee(const string& fn, const string& ln, const string& ssn, const string& company_name, int commission = 0) :
		employee(fn, ln, ssn), _company_name(company_name), _commission(_commission)
	{
		if ( is_output_displayed )
		{
			cout << "commission employee constructor" << endl;
		}
	}

	virtual ~commissionemployee() 
	{
		if ( is_output_displayed )
		{
			cout << "commission employee destructor" << endl;
		}
	}

	commissionemployee(const commissionemployee& ce) :
		employee(ce), _company_name(ce._company_name), _commission(ce._commission)
	{
		if ( is_output_displayed )
		{
			cout << "commission employee copy constructor" << endl;
		}
	}

	commissionemployee& operator=(const commissionemployee& ce)
	{
		if ( &ce != this )
		{
			employee::operator=(ce);
			_company_name = ce._company_name;
			_commission = ce._commission;
		}
		return *this;
	}

	friend ostream& operator<<(ostream &output, const commissionemployee &ce)
	{
		const employee& e = ce;
		output << e << endl;
		output << "Company name: " << ce._company_name << endl;
		output << "Commission: " << ce._commission << endl;
		return output;
	}

private:
	string _company_name;
	int _commission;
};