#include "Chrono.h"
#include "std_lib_facilities_4.h"

struct Currency{
public:
    Currency(string t,double r);
	Currency();
    
    string getCurrency_type();
    
    double getexchange_rate();
	
    string type;
    double rate;
};

class Patron{
	string patronName;
	double money;
	int idNum;
	
	public:
	
	Patron();
	Patron(string first, string second);
	Patron(string n, int d, int m);
	
	string get_Name();
	void set_Name(string str);
	double get_Money();
	void set_Money(double mon);
	int get_idNum();
	void set_idNum(int num);
	void change_Id();
};

struct Transaction{
    
	
    Transaction(Patron, Chrono::Date, Chrono::Time, string, double);
    
    Patron getcustomer();
    
    Chrono::Date gettransaction_date();
    
    Chrono::Time gettransaction_time();
    
    string gettransaction_type();
    
    double gettransaction_amount();
    
    Patron customer;
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
	Money();
};

class Bank
{
	protected:
	Vector<Patron> pats;
	Vector<Transaction> trans;
	Money cash;
	double getTotalMoney();
	void withdrawal();
	void deposit();
	void newPatron();
	void get_Transactions();
	void get_Patrons();
	void save_file();
	
	
	public:
	void read();
	void menu();
	Bank();
};

class BankIntl : public Bank
{
	protected:
	void deposit();
	void withdrawal();
	void save_file();
	double get_rate(string,string);
	
	public:
	void read();
	void menu();
};

ostream& operator<<(ostream&, Patron&);
ostream& operator<<(ostream&, Transaction&);