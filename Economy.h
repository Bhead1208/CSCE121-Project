
include "Chrono.h"
include "std_lib_facilities_4.h"

struct Currency{
public:
    Currency(string type,double rate);
    
    string getCurrency_type();
    
    double getexchange_rate();
    
private:
    string currency_type;
    double exchange_rate;
};

class Patron{
	string patronName;
	double money;
	int idNum;
	
	public:
	
	Patron();
	Patron(string first, string second);
	
	string get_Name();
	void set_Name(string str);
	double get_Money();
	void set_Money(double mon);
	int get_idNum();
};

struct Transaction{
public:
    
    Transaction(Patron::Patron cust,Chrono::Date date,Chrono::Time time,string type,double amount);
    
    Patron::Patron getcustomer();
    
    Chrono::Date gettransaction_date();
    
    Chrono::Time gettransaction_time();
    
    string gettransaction_type();
    
    double gettransaction_amount();
    
    
private:
    Patron::Patron customer;
    Chrono::Date transaction_date;
    Chrono::Time transaction_time;
    string transaction_type;
    double transaction_amount;
    
};

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
