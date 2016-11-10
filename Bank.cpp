#include "std_lib_facilities_4.h"

class Bank()
{
	Vector<Patron> pats;
	Vector<Tranction> trans;
	Money cash;
	double getTotalMoney() const;
	void withdrawal();
	void deposit();
	void newPatron();
	void getTransactions() const;
	void getPatrons() const;
	
	public:
	void menu();
	Bank();
};

Bank::getTransactions()
{
	for (Transaction t : trans)
	{
		//display
	}
}