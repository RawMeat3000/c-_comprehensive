#include "employee.h"


class basepluscommissionemployee : public commissionemployee
{
public:
	//e1("jag", "vasudevamurthy", "678-90", "BELL", 560, "abc", 89);
	basepluscommissionemployee(string fn, string ln, string ssn, string company_name, int salary, string ticker, int stock_price) :
		commissionemployee(fn, ln, ssn, company_name, salary), _ticker(ticker), _stock_price(stock_price)
	{
		cout << "commission employee constructor" << endl;
	}

	basepluscommissionemployee(const basepluscommissionemployee& ce) :
		commissionemployee(ce), _ticker(ce._ticker), _stock_price(ce._stock_price)
	{
			cout << "commission employee copy constructor" << endl;
	}

	basepluscommissionemployee& operator=(const basepluscommissionemployee& bpce)
	{
		if ( &bpce != this )
		{
			employee::operator=(bpce);
			_ticker = bpce._ticker;
			_stock_price = bpce._stock_price;
		}
		return *this;
	}

private:
	string _ticker;
	int _stock_price;
};