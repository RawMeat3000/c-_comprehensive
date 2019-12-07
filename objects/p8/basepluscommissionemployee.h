#include "employee.h"


class basepluscommissionemployee : public commissionemployee
{
public:
	//e1("jag", "vasudevamurthy", "678-90", "BELL", 560, "abc", 89);
	basepluscommissionemployee(const string& fn, const string& ln, const string& ssn, const string& company_name, int salary, const string& ticker, int stock_price = 0) :
		commissionemployee(fn, ln, ssn, company_name, salary), _ticker(ticker), _stock_price(stock_price)
	{
		if ( is_output_displayed )
		{
			cout << "commission employee constructor" << endl;
		}
	}

	basepluscommissionemployee(const basepluscommissionemployee& ce) :
		commissionemployee(ce), _ticker(ce._ticker), _stock_price(ce._stock_price)
	{
		if ( is_output_displayed )
		{
			cout << "commission employee copy constructor" << endl;
		}
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

	friend ostream& operator<<(ostream &output, const basepluscommissionemployee &bpce)
	{
		const commissionemployee& ce = bpce;
		output << ce << endl;
		output << "Ticker: " << bpce._ticker << endl;
		output << "Stock price: " << bpce._stock_price << endl;
		return output;
	}

private:
	string _ticker;
	int _stock_price;
};