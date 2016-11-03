/* Bryan Head
 * Cash Program
 * CSCE 121 Sect 512
 * Hi
 */


#include "std_lib_facilities_4.h"

struct Currency
{
	double rate;
	string type;
	Currency(string);
	void setType(string);
};

Currency::Currency(string t)
{
	type = t;
	if (t == "USD") rate = 1.0;
	else rate = 1.0;
}

void Currency::setType(string t)
{
	type = t;
	if (t == "USD") rate = 1.0;
	else rate = 1.0;
}

/* class Patron
{
	public:
	double amount;
	string name;
};

double Patron::getAmount()
{
	return amount;
} */

class Money
{
	Currency cur;
	double amount;
	public:
	Currency getCurrency();
	void setCurrency(string);
	double getAmount();
	void setAmount(double);
};

Currency Money::getCurrency()
{
	return cur;
}

void Money::setCurrency(string t)
{
	cur.setType("USD");
}

double Money::getAmount()
{
	return amount;
}

void Money::setAmount(double a)
{
	amount = a;
}

int main()
{
	return 0;
}