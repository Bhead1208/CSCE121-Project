#include "std_lib_facilities_4.h";
#include "Chrono.h";
#include "Economy.h"

Currency::Currency(string type,double rate)
    :currency_type(type),exchange_rate(rate)
{}

string Currency::getCurrency_type()
{
    return currency_type;
}

double Currency::getexchange_rate()
{
    return exchange_rate;
}

//--------------------

Patron::Patron(){
	patronName = "Jhon"+"-"+"Doe";
	money = 0;
	idNum = 000000000;
}
Patron::Patron(string first, string second){
	patronName = first +"-"+ second;
	money = 0;
	idNum = 000000000;
}
void Patron::get_Name(){
	return PatronName;
}
void Patron::set_Name(string str){
	patronName = str;
}
double Patron::get_Money(){
	return money;
}
void Patron::set_Money(double mon){
	money = mon;
}
int Patron::get_idNum(){
	return id; 
}
int Patron::set_idNum(num){
	idNum = num;
}

//--------------------

Transaction(Patron::Patron cust,Chrono::Date date,Chrono::Time time,string type,double amount)
:customer(cust),transaction_date(date),transaction_time(time),transaction_type(type),transaction_amount(amount)
{}

Patron::Patron getcustomer()
{
    return customer;
}

Chrono::Date gettransaction_date()
{
    return transaction_date;
}

Chrono::Time gettransaction_time()
{
    return transaction_time;
}

string gettransaction_type()
{
    return transaction_type;
}

double gettransaction_amount()
{
    return transaction_amount;
}

//--------------------

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

//--------------------

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
