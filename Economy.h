#include "Chrono.h"
#include "std_lib_facilities_4.h"

struct Currency{
public:
    Currency(string t,double r);
	Currency();
    
    string getCurrency_type();
    
    double getexchange_rate();
	void setType(string);
	
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
	
	double getTotalMoney();
	void withdrawal();
	void deposit();
	void newPatron(string strFirst, string strLast);
	void get_Transactions();
	void get_Patrons();
	void save_file();
	
	
	public:
	void read();
	Money cash;
	void menu();
	Bank();
};

class BankIntl : public Bank
{
	public:
	
	void save_file();
	double get_rate(string,string);
	double getTotalMoney(string str);
	void newPatron(string, string);
	void add(string str, double mon); // takes string for cureency type and double 
	void remove(string str,double mon);
	
	
	void read();
	void menu();
	void deposit(int num, string cur, double amountMon);
	void withdrawal(int id, string cur, double amount);
	bool findPatron(int);
	Vector<Patron> getPats() {return pats;}
	Vector<Transaction> getTrans() {return trans;}
	BankIntl();
	void newPatron(string str1, string str2, int newID);
};

ostream& operator<<(ostream&, Patron&);
ostream& operator<<(ostream&, Transaction&);
void PatronTransfer(BankIntl&,BankIntl&);
void bigRead();
void bigSave();