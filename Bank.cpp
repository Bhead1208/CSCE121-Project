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

void Bank::getTransactions()
{
	for (Transaction t : trans)
	{
		//display
	}
}

double Bank::getTotalMoney()
{
	double sum = 0;
	for(Patron p : pats)
	{
		sum += p.getAmount();
	}
}

Bank::Bank()
{
	cout << "Input file name: ";
	string name;
	cin >> name;
	ifstream file(name);
	if (file.good())
	{
		//read file	
	}
	else
	{
		cash.setAmount(6000);
	}
}
