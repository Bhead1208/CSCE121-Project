#include "std_lib_facilities_4.h"
#include "Economy.h"

Currency::Currency(string t,double r)
    :type(type),rate(rate)
{}

Currency::Currency()
{}

string Currency::getCurrency_type()
{
    return type;
}

double Currency::getexchange_rate()
{
    return rate;
}

//--------------------

Patron::Patron(){
	patronName = "John-Doe";
	money = 0;
	idNum = rand() % 1000000 + 1;
}
Patron::Patron(string first, string second){
	patronName = first +"_"+ second;
	money = 0;
	idNum = rand() % 1000000 + 1;
}
string Patron::get_Name(){
	return patronName;
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
	return idNum; 
}
void Patron::set_idNum(int num){
	idNum = num;
}
void Patron::change_Id()
{
	idNum = rand() % 1000000 + 1;
}

//--------------------

Transaction::Transaction(Patron cust, Chrono::Date d, Chrono::Time t, string type, double amount)
:customer(cust),transaction_date(d),transaction_time(t),transaction_type(type),transaction_amount(amount)
{}

Patron Transaction::getcustomer()
{
    return customer;
}

Chrono::Date Transaction::gettransaction_date()
{
    return transaction_date;
}

Chrono::Time Transaction::gettransaction_time()
{
    return transaction_time;
}

string Transaction::gettransaction_type()
{
    return transaction_type;
}

double Transaction::gettransaction_amount()
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
	cur.type = "USD";
}

double Money::getAmount()
{
	return amount;
}

void Money::setAmount(double a)
{
	amount = a;
}

Money::Money()
{
	amount = 6000;
	Currency c("USD", 1.0);
	cur = c;
}

//--------------------

void Bank::getTransactions() const
{
	for (Transaction t : trans)
	{
		//display
	}
}

double Bank::getTotalMoney() const
{
	double sum = 0;
	for(Patron p : pats)
	{
		sum += p.get_Money();
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

/*
	Function Deposit 
	Asks for a patron ID and, if they exist, create a transaction object with the
	attributes the patron object (reference) and "Deposit."
	@param vactor of integers
	@return void returns nothing
*/
void Bank::deposit(){
	int num;
	bool valid;	
	cout<<"Enter Id"<<endl;
	cin>>num;
	
	// for loop checks trough vector of id's to see if id exists
	Patron customer;
	for(int i = 0; i < pats.size(); i++){
		if(pats[i].get_idNum() == num){
			valid = true;
			customer = pats[i];
			break;
		}
	}
	if(valid){
		int hou, min, sec, dd, mm, yy;
		// getting data from user to create time object
		cout<<"Enter Time"<<endl;
		cout<<"Enter Hour"<<endl; 
		cin>> hou; // stroes hour
		cout<<"Enter Minute"<<endl;
		cin>> min;// stores minute
		cout<<"Enter Second"<<endl;
		cin>> sec;// stores second
		Chrono::Time timeObj(hou,min,sec);//might have built object incorrectly come back and check
		cout<<"Enter Date"<<endl;
		cout<<"Enter Day"<<endl; 
		cin>> dd; // stroes hour
		cout<<"Enter Month"<<endl;
		cin>> mm;// stores minute
		cout<<"Enter Year"<<endl;
		cin>> yy;// stores second
		Chrono::Date dateObj(yy,Chrono::Date::Month(mm),dd); // might have built object incorrectly come back and check
		cout<<"Enter Currency Type"<<endl;
		string strCurrency;
		cin>> strCurrency;
		cout<<"Enter Amount"<<endl;
		double amountMon;
		cin>> amountMon;
			
		Transaction transObj(customer ,dateObj,timeObj,strCurrency,amountMon);
	}
	else cout<<" NO MATCHING ACCOUNT FOR THIS ID "<<endl;
}

//--------------------

int main()
{
	
}