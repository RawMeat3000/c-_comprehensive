#include "employee.h"

class commissionemployee : public employee
{
public:
	commissionemployee(string fn, string ln, string ssn, string company_name, int commission) :
		employee(fn, ln, ssn), _company_name(company_name), _commission(_commission)
	{
		cout << "commission employee constructor" << endl;
	}

	commissionemployee(const commissionemployee& ce) :
		employee(ce), _company_name(ce._company_name), _commission(ce._commission)
	{
		cout << "commission employee copy constructor" << endl;
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

private:
	string _company_name;
	int _commission;
};