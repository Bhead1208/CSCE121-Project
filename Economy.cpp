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
	int index=0;
	for(int i = 0; i < pats.size(); i++){
		if(pats[i].get_idNum() == num){
			valid = true;
			index=i;
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
		/* cout<<"Enter Currency Type"<<endl;
		string strCurrency;
		cin>> strCurrency; */
		cout<<"Enter Amount"<<endl;
		double amountMon;
		cin>> amountMon;
			
		Transaction transObj(customer ,dateObj,timeObj,"Deposit",amountMon);
		trans.push_back(transObj);
		
		pats.at(index).set_Money(pats.at(index).get_Money()+amountMon);
	}
	else cout<<" NO MATCHING ACCOUNT FOR THIS ID "<<endl;
}

void Bank::withdrawal(){
	int num;
	bool valid;	
	cout<<"Enter Id"<<endl;
	cin>>num;
	
	// for loop checks trough vector of id's to see if id exists
	Patron customer;
	int index;
	for(int i = 0; i < pats.size(); i++){
		if(pats[i].get_idNum() == num){
			valid = true;
			customer = pats[i];
			index = i;
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
		/* cout<<"Enter Transaction Type"<<endl;
		string strType;
		cin>> strType; */
		cout<<"Enter Amount"<<endl;
		double amountMon;
		cin>> amountMon;
		
		if (pats.at(index).get_Money()>=amountMon)
		{
			Transaction transObj(customer ,dateObj,timeObj,"Withdrawal",amountMon);
			trans.push_back(transObj);
			
			pats.at(index).set_Money(pats.at(index).get_Money()-amountMon);
		}
		else
		{
			cout << "Overdraw Error" << endl;
		}
	}
	else cout<<" NO MATCHING ACCOUNT FOR THIS ID "<<endl;
}

void Bank::get_Transactions()
{
    for (int i=0; i<trans.size();i++){
        //cout << trans[i] << endl;
    }
}

void Bank::get_Patrons()
{
    for (int i=0; i<pats.size();i++){
        //cout << pats[i] << endl;
    }
}

void Bank::save()
{
	
}

void Bank::newPatron()
{
	string strFirst;
	string strLast;
	cout<< "Enter First Name"<<endl;
	cin >> strFirst;
	cout << "Enter Last Name"<<endl;
	cin >> strLast;
	
	Patron newPat(strFirst,strLast);
	
	bool pass = true;
	while(pass)
	for(int i = 0; i < pats.size(); i++){
		if(pats[i].get_idNum() == newPat.get_idNum()){
			change_Id();
		}
		else 
		{
			pass= false;
			break;
		}
	}
	
	pats.push_back(newPat);
}

void Bank::menu()
{
	bool stop = false;
	while (!stop)
	{
		cout << "Enter an option: ";
		int option;
		cin >> option;
		switch(option)
		{
			case 1: withdrawal(); break;
			case 2: deposit(); break;
			case 3: newPatron(); break;
			case 4: get_Transactions(); break;
			case 5: get_Patrons(); break;
			case 6: stop = true; break;
			default: cout << "wut\n";
		}
	}
	cout << "Would you like to save? y/n: ";
	char c;
	cin >> c;
	if (c=='Y')
	{
		save();
	}
}

//--------------------

ostream& operator<<(ostream& os, Patron& p)
{
	return os << p.get_Name() << " " << p.get_idNum() << " " << p.get_
		();
}

ostream& operator<<(ostream& os, Transaction& t)
{
	return os << t.getcustomer().get_Name() << " " << t.gettransaction_date() << " " << t.gettransaction_time() << " " << t.gettransaction_type() << " " <<  t.gettransaction_amount();
}

istream& operator>>(istream& is, Patron& p)
{
    string name;
    int idNum;
    double money;
    char ch1, ch2, ch3, ch4;
    is >> name >> ch2 >> idNum >> ch3 >> money >>;
    if (!is) return is;
    if (ch1!=' ' || ch2!=' ' || ch3!=' ') { // oops: format error
        is.clear(ios_base::failbit);
        
        return is;
    }
    p = Patron(name,idNUm,money);
    return is;
   
}

istream& operator>>(istream& is, Transaction& t)
{
    string name;
    Chrono::Date d;
    Chrono::Time tt;
    string type;
    double amount;
    char ch1, ch2, ch3, ch4;
    is >> name >> ch1 >> d >> ch2 >> tt >> ch3 >> type >> ch4>> amount;
    if (!is) return is;
    if (ch1!=' ' || ch2!=' ' || ch3!=' ' || ch4!=' ') { // oops: format error
        is.clear(ios_base::failbit);                    // set the fail bit
        return is;
    }
    t = Transaction(name,d,tt,type,amount);
    return is;
    
}
//--------------------

int main()
{
	Patron p("John", "Memer");
	cout << p << endl;
	Chrono::Date d;
	Chrono::Time now;
	Transaction t(p,d,now,"Withdrawal",2);
	cout << t;
}
