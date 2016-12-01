#include "std_lib_facilities_4.h"
#include "Economy.h"
/*
	Currency constructor 
	@param1 string
	@param2 double
	setes type and rate based on parameter
	
*/
 Currency::Currency(string t,double r)
    :type(t),rate(r)
{} 
/*
	Default Currency constructor 
	@param1 string
	@param2 double
	sets type and rate to default
	
*/
Currency::Currency()
{}
/*
	Function returns currency
	@return string
	
*/
string Currency::getCurrency_type()
{
    return type;
}
/*
	Function returns exchange rate
	@return double
	
*/
double Currency::getexchange_rate()
{
    return rate;
}

//--------------------
/*
	default constructor sets patronName money and idnum to values
*/
Patron::Patron(){
	patronName = "John-Doe";
	money = 0;
	idNum = rand() % 1000000 + 1;
}
/*
	Patron creates patron object 
	@param1 string
	@param2 string
*/
Patron::Patron(string first, string second){
	patronName = first +"_"+ second;
	money = 0;
	idNum = rand() % 1000000 + 1;
}
/*
	Patron constructor creates patron object sets money also
	@param1 string
	@param2 int
	@param3 int
*/
Patron::Patron(string n, int d, int m)
: patronName(n),money(m),idNum(d)
{}
string Patron::get_Name(){
	return patronName;
}
/*
	function sets name
	@param1 string
	
*/
void Patron::set_Name(string str){
	patronName = str;
}
/*
	function returns money
	@param1 none
	
*/
double Patron::get_Money(){
	return money;
}
/*
	function sets money
	@param1 double
	
*/
void Patron::set_Money(double mon){
	money = mon;
}
/*
	function gets idnum
	@return int
	
*/
int Patron::get_idNum(){
	return idNum; 
}
/*
	function sets idnum
	@param1 int
	
*/
void Patron::set_idNum(int num){
	idNum = num;
}
/*
	function changes id redoes the rand
	@param1 string
	
*/
void Patron::change_Id()
{
	idNum = rand() % 1000000 + 1;
}

//--------------------
/*
	Transactions constructor
	sets patron date time string currency type and amount
	@param1 Patron
	@param2 Date 
	@param3 Time
	@param4 string
	@param5 double
	
*/
Transaction::Transaction(Patron cust, Chrono::Date d, Chrono::Time t, string type, double amount)
:customer(cust),transaction_date(d),transaction_time(t),transaction_type(type),transaction_amount(amount)
{}
/*
	function gets Patron object
	@return1 Patron
	
*/
Patron Transaction::getcustomer()
{
    return customer;
}
/*
	function gets date
	@return Date
	
*/
Chrono::Date Transaction::gettransaction_date()
{
    return transaction_date;
}
/*
	function gets time
	@return Time
	
*/
Chrono::Time Transaction::gettransaction_time()
{
    return transaction_time;
}
/*
	function gets Tansaction
	@returns Transaction
	
*/
string Transaction::gettransaction_type()
{
    return transaction_type;
}
/*
	function gets amount
	@return double
	
*/
double Transaction::gettransaction_amount()
{
    return transaction_amount;
}

//--------------------
/*
	function gets currency
	@return Currency
	
*/
Currency Money::getCurrency()
{
	return cur;
}
/*
	function sets currency type
	@param1 string
	
*/
void Money::setCurrency(string t)
{
	cur.type = "USD";
}
/*
	function gets Amount
	@returns double
	
*/
double Money::getAmount()
{
	return amount;
}
/*
	function sets Amount
	@param double
	
*/
void Money::setAmount(double a)
{
	amount = a;
}
/*
	Money Default Constructor
	sets amount currency typeand  Currency object 
	
*/
Money::Money()
{
	amount = 6000;
	string name = "USD";
	Currency c(name, 1.0);
	cur = c;
}

//--------------------
/*
	Bank Default Constructor
	
*/
Bank::Bank() 
{
	cash.setAmount(6000.0);
	cash.getCurrency().type = "USD";
	read();
};
/*
	
	
*/
void Bank::read()
{
	pats.reserve(100);
	trans.reserve(100);
	cout << "File name?: ";
	string fname;
	cin >> fname;
	ifstream file(fname);
	if (file.good())
	{
		string s;
		getline(file,s);
		cash.getCurrency().type = s;
		getline(file,s);
		cash.setAmount(stod(s));
		int numPats;
		getline(file,s);
		numPats = stoi(s);
		for (int i = 0; i < numPats; i++)
		{
			string patLine;
			getline(file,patLine);
			Vector<string> vs;
			stringstream ss;
			ss.str(patLine);
			string item;
			while (getline(ss, item, ' '))
			{
				vs.push_back(item);
			}
			Patron p(vs[0],stoi(vs[1]),stoi(vs[2]));
			pats.push_back(p);
		}
		int numTrans;
		getline(file,s);
		numTrans = stoi(s);
		for (int i = 0; i < numTrans; i++)
		{
			string tLine;
			getline(file,tLine);
			Vector<string> vs;
			stringstream ss;
			ss.str(tLine);
			string item;
			while (getline(ss, item, ' '))
			{
				vs.push_back(item);
			}
			//Read values from vector into trans object
			//name date time type amount
			istringstream istr(vs[1]);
			Chrono::Date da;
			istr >> da;
			
			Chrono::Time ti;
			istr.str(vs[2]);
			istr >> ti;
			
			//search patron array
			int index;
			for(int i = 0; i < pats.size(); i++){
				if(pats[i].get_Name() == vs[0]){
					index = i;
					break;
				}
			}
			Transaction tr(pats[index],da,ti,vs[3],stod(vs[4]));
			trans.push_back(tr);
		}
	}
	else
	{
		cout << "no file" << endl;
	}
	cout << "Bank amount: "<< cash.getAmount() << " " << cash.getCurrency().type << endl;
	cout << "Patrons: " << endl;
	for (Patron x : pats)
	{
		cout << x << " " << cash.getCurrency().type << endl;
	}
	cout << "Transactions: " << endl;
	for (Transaction x : trans)
	{
		cout << x << " " << cash.getCurrency().type << endl;
	}
}
/*
	function gets the total money of patron
	@retrun double
	
*/
double Bank::getTotalMoney()
{
	double sum = 0;
	for(Patron p : pats)
	{
		sum += p.get_Money();
	}
	cout << sum+cash.getAmount() << " " << cash.getCurrency().type << endl;
	return sum+cash.getAmount();
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
		Chrono::Time timeObj(hou,min,sec);
		cout<<"Enter Date"<<endl;
		cout<<"Enter Day"<<endl; 
		cin>> dd; // stroes hour
		cout<<"Enter Month"<<endl;
		cin>> mm;// stores minute
		cout<<"Enter Year"<<endl;
		cin>> yy;// stores second
		Chrono::Date dateObj(yy,Chrono::Date::Month(mm),dd); 
		cout<<"Enter Amount"<<endl;
		double amountMon;
		cin>> amountMon;
			
		Transaction transObj(customer ,dateObj,timeObj,"Deposit",amountMon);
		trans.push_back(transObj);
		
		pats.at(index).set_Money(pats.at(index).get_Money()+amountMon);
	}
	else cout<<" NO MATCHING ACCOUNT FOR THIS ID "<<endl;
}
/*
	Function checks if id exists if it does then if it does lets patron deposit
	
	
*/
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
		Chrono::Time timeObj(hou,min,sec);
		cout<<"Enter Date"<<endl;
		cout<<"Enter Day"<<endl; 
		cin>> dd; // stroes hour
		cout<<"Enter Month"<<endl;
		cin>> mm;// stores minute
		cout<<"Enter Year"<<endl;
		cin>> yy;// stores second
		Chrono::Date dateObj(yy,Chrono::Date::Month(mm),dd);
		
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
/*
	Function gets things in trasactions object
	couts transctions vector
	
*/
void Bank::get_Transactions()
{
    for (int i=0; i<trans.size();i++){
        cout << trans[i] << endl;
    }
}
/*
	Function gets things in patrons object
	couts patrons vector
	
*/
void Bank::get_Patrons()
{
    for (int i=0; i<pats.size();i++){
        cout << pats[i] << endl;
    }
}
/*
	ofstream to read file onto file to save users info
	
*/
void Bank::save_file()
{
	string nn;
    cout << "What file name?: ";
    cin>>nn;
    ofstream file(nn);
    file << cash.getCurrency().type<<"\n";
	file << cash.getAmount()<<"\n";
    file << pats.size()<<"\n";
    for(Patron x: pats)
    {
        file<< x << "\n";
    }
    file << trans.size()<<"\n";
    for(Transaction x: trans)
    {
        file<< x << "\n";
    }
}
/*
	Function to add new patron if patron doesnt excist
	pushes new patron into vector of Patron objects
	
*/
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
	while(pass && (pats.size()!=0))
	for(int i = 0; i < pats.size(); i++){
		if(pats[i].get_idNum() == newPat.get_idNum()){
			newPat.change_Id();
		}
		else 
		{
			pass= false;
			break;
		}
	}
	pats.push_back(newPat);
}
/*
	Function displays menu 
	
*/
void Bank::menu()
{
	bool stop = false;
	while (!stop)
	{
		cout << "(1) Withdrawal" << endl;
		cout << "(2) Deposit" << endl;
		cout << "(3) New Patron" << endl;
		cout << "(4) Display Transactions" << endl;
		cout << "(5) Display Patrons" << endl;
		cout << "(6) Total Money" << endl;
		cout << "(7) Quit" << endl;
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
			case 6: getTotalMoney(); break;
			case 7: stop = true; break;
			default: cout << "wut\n";
		}
	}
	cout << "Would you like to save? y/n: ";
	char c;
	cin >> c;
	if (c=='Y' || c=='y')
	{
		save_file();
	}
}

//--------------------
/*
	overloaded ostream operator
	to cout Patron
	
*/
ostream& operator<<(ostream& os, Patron& p)
{
	return os << p.get_Name() << " " << p.get_idNum() << " " << p.get_Money();
}
/*
	overloaded ostream operator
	to cout Transaction
	
*/
ostream& operator<<(ostream& os, Transaction& t)
{
	return os << t.getcustomer().get_Name() << " " << t.gettransaction_date() << " " << t.gettransaction_time() << " " << t.gettransaction_type() << " " <<  t.gettransaction_amount();
}
/*
	overloaded istream operator
	to cin Patron
	
*/
istream& operator>>(istream& is, Patron& p)
{
    string name;
    int idNum;
    double money;
    char ch1, ch2, ch3, ch4;
    is >> name >> ch2 >> idNum >> ch3 >> money;
    if (!is) return is;
    if (ch1!=' ' || ch2!=' ' || ch3!=' ') { // oops: format error
        is.clear(ios_base::failbit);
        
        return is;
    }
    p = Patron(name,idNum,money);
    return is;
   
}
/*
	overloaded istream operator
	to cin TTransaction
	
*/
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
	Patron p;
	p.set_Name(name);
    t = Transaction(p,d,tt,type,amount);
    return is;
    
}

//--------------------
/*
	Function gets international bank rate based on parameter
	@param1 string
	@param2 string
	@return double
	
*/
double BankIntl::get_rate(string s, string r)
{
	double num;
	double den;
	if (s == "USD")
	{
		num = 1.0;
	}
	else if (s == "GBP")
	{
		num =.76;
	}
	else if (s == "EUR")
	{
		num = .89;
	}
	else if (s == "JPY")
	{
		num = 102.09;
	}
	else if (s == "RUB")
	{
		num = 65.97;
	}
	else
	{
		num = 1.0;
	}
	
	if (r == "USD")
	{
		den = 1.0;
	}
	else if (r == "GBP")
	{
		den =.76;
	}
	else if (r == "EUR")
	{
		den = .89;
	}
	else if (r == "JPY")
	{
		den = 102.09;
	}
	else if (r == "RUB")
	{
		den = 65.97;
	}
	else
	{
		den = 1.0;
	}
	
	return num/den;
}
/*
	Functions Lets patron withdraw if their id exists
	
*/
void BankIntl::withdrawal(int num, string cur, double amountMon){
	//cout<< "What Currency Would You Like to withdrawal"<<endl;
	//string str;
	//cin >> str;
	double val = get_rate(cur,cash.getCurrency().type);
	//money in us
	//ask for euro
	//g_r(euro,us)
	//returns euro/us
	//euro/(euro/us)=us
	//divide
	//int num;
	bool valid;	
	//cout<<"Enter Id"<<endl;
	//cin>>num;
	
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
		// getting data from user to create time object
		/* cout<<"Enter Time"<<endl;
		cout<<"Enter Hour"<<endl; 
		cin>> hou; // stroes hour
		cout<<"Enter Minute"<<endl;
		cin>> min;// stores minute
		cout<<"Enter Second"<<endl;
		cin>> sec;// stores second */
		
		auto ti = time(nullptr);
		auto tim = *localtime(&ti);

		ostringstream ossi;
		ossi << put_time(&tim, "%H %M %S");
		auto stri = ossi.str();

		//cout << "Current Time is " << str << endl;

		int hour; int minute; int second;
		istringstream issi(stri);
		issi >> hour >> minute >> second;
		
		Chrono::Time timeObj(hour,minute,second);//might have built object incorrectly come back and check
		/* cout<<"Enter Date"<<endl;
		cout<<"Enter Day"<<endl; 
		cin>> dd; // stroes hour
		cout<<"Enter Month"<<endl;
		cin>> mm;// stores minute
		cout<<"Enter Year"<<endl;
		cin>> yy;// stores second */
		
			auto t = time(nullptr);
			auto tm = *localtime(&t);

			ostringstream oss;
			oss << put_time(&tm, "%d %m %Y");
			auto str = oss.str();

			//cout << "Current Date is " << str << endl;

			int day; int month; int year;
			istringstream iss(str);
			iss >> day >> month >> year;
			int y = year;
			Chrono::Date::Month m = Chrono::Date::Month(month);
			int d = day;
		
		Chrono::Date dateObj(y,m,d); // might have built object incorrectly come back and check
	     
		//cout<<"Enter Amount"<<endl;
		//double amountMon;
		//cin>> amountMon;
		
		if (pats.at(index).get_Money()>=amountMon)
		{
			Transaction transObj(customer ,dateObj,timeObj,"Withdrawal",amountMon/val);
			trans.push_back(transObj);
			
			pats.at(index).set_Money(pats.at(index).get_Money()-amountMon/val);
		}
		else
		{
			cout << "Overdraw Error" << endl;
		}
	}
	else cout<<" NO MATCHING ACCOUNT FOR THIS ID "<<endl;
}

/*
	Function adds to bank in any currency
*/
void BankIntl::deposit(int num, string cur, double amountMon){
	/* cout<< "What Currency Would You Like to deposit"<<endl;
	string str;
	cin >> str; */
	double val = get_rate(cur,cash.getCurrency().type);
	//money in us
	//ask for euro
	//g_r(euro,us)
	//returns euro/us
	//euro/(euro/us)=us
	//divide
	//int num;
	bool valid;	
	// cout<<"Enter Id"<<endl;
	// cin>>num;
	
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
		/* cout<<"Enter Time"<<endl;
		cout<<"Enter Hour"<<endl; 
		cin>> hou; // stroes hour
		cout<<"Enter Minute"<<endl;
		cin>> min;// stores minute
		cout<<"Enter Second"<<endl;
		cin>> sec;// stores second */
		
		auto ti = time(nullptr);
		auto tim = *localtime(&ti);

		ostringstream ossi;
		ossi << put_time(&tim, "%H %M %S");
		auto stri = ossi.str();

		//cout << "Current Time is " << str << endl;

		int hour; int minute; int second;
		istringstream issi(stri);
		issi >> hour >> minute >> second;
		
		Chrono::Time timeObj(hour,minute,second);//might have built object incorrectly come back and check
		/* cout<<"Enter Date"<<endl;
		cout<<"Enter Day"<<endl; 
		cin>> dd; // stroes hour
		cout<<"Enter Month"<<endl;
		cin>> mm;// stores minute
		cout<<"Enter Year"<<endl;
		cin>> yy;// stores second */
		
			auto t = time(nullptr);
			auto tm = *localtime(&t);

			ostringstream oss;
			oss << put_time(&tm, "%d %m %Y");
			auto str = oss.str();

			//cout << "Current Date is " << str << endl;

			int day; int month; int year;
			istringstream iss(str);
			iss >> day >> month >> year;
			int y = year;
			Chrono::Date::Month m = Chrono::Date::Month(month);
			int d = day;
		
		Chrono::Date dateObj(y,m,d); // might have built object incorrectly come back and check
	     
		// cout<<"Enter Amount"<<endl;
		// double amountMon;
		// cin>> amountMon;
		Transaction transObj(customer ,dateObj,timeObj,"Deposit",amountMon/val);
		trans.push_back(transObj);
		pats.at(index).set_Money(pats.at(index).get_Money()+amountMon/val);
	}
	else cout<<" NO MATCHING ACCOUNT FOR THIS ID "<<endl;
}

/*
	Asks the user for a currency to convert TO
	Generates the multiplier with get_rate()
	Multiplies all money values by this multiplier
	sums them up and dipays the sum and the currency asked for
*/
double BankIntl::getTotalMoney()
{
	cout<< "What Currency Would You Like to display?"<<endl;
	string str;
	cin >> str;
	double val = get_rate(str,cash.getCurrency().type);
	double sum = 0;
	for(Patron p : pats)
	{
		sum += p.get_Money()*val;
	}
	cout << sum+cash.getAmount()*val << " " << str << endl;
	return sum+cash.getAmount()*val;
}

/*
	See Bank::read();
*/
void BankIntl::read()
{
	Bank::read();
}

/*
	See Bank::save_file()
*/
void BankIntl::save_file()
{
	Bank::save_file();
}

/*
	See Bank::newPatron();
*/
void BankIntl::newPatron()
{
	Bank::newPatron();
}
/*
	Function adds to bank in any currency
	
	
*/
void BankIntl::add()
{
	cout<< "What Currency Would You Like to deposit"<<endl;
	string str;
	cin >> str;
	double val = get_rate(str,cash.getCurrency().type);
	cout << "How much?: ";
	double mon;
	cin >> mon;
	cash.setAmount(cash.getAmount()+mon/val);
}
/*
	Function removes from bank 
	
	
*/
void BankIntl::remove()
{
	cout<< "What Currency Would You Like to withdrawal"<<endl;
	string str;
	cin >> str;
	double val = get_rate(str,cash.getCurrency().type);
	cout << "How much?: ";
	double mon;
	cin >> mon;
	cash.setAmount(cash.getAmount()-mon/val);
}
bool BankIntl::findPatron(int num)
{
	for (Patron x : pats)
	{
		if (x.get_idNum()==num)
		{
			return true;
		}
	}
	return false;
}

/*
	See Bank::menu()
	new function to use the native Intl functions
*/
void BankIntl::menu()
{
	bool stop = false;
	while (!stop)
	{
		cout << "Available options:" << endl;
		cout << "(1) Withdrawal" << endl;
		cout << "(2) Deposit" << endl;
		cout << "(3) New Patron" << endl;
		cout << "(4) Display Transactions" << endl;
		cout << "(5) Display Patrons" << endl;
		cout << "(6) Total Money" << endl;
		cout << "(7) Add money to bank" << endl;
		cout << "(8) Remove money from bank" << endl;
		cout << "(9) Quit" << endl;
		cout << "Enter an option: ";
		int option;
		cin >> option;
		switch((int)option)
		{
			case 1: withdrawal(100, "", 1.0); break;
			case 2: deposit(100, "", 1.0); break;
			case 3: newPatron(); break;
			case 4: get_Transactions(); break;
			case 5: get_Patrons(); break;
			case 6: getTotalMoney(); break;
			case 7: add(); break;
			case 8: remove(); break;
			case 9: stop = true; break;
			default: break;
		}
	}
	cout << "Would you like to save? y/n: ";
	char c;
	cin >> c;
	if (c=='Y' || c=='y')
	{
		save_file();
	}
}
/*
	See Bank::Bank();
*/
BankIntl::BankIntl()
{
	
}

//-------------------

void PatronTransfer(BankIntl& from,BankIntl& to)
{
	//get id num
	int idee = 100;
	//check both 
	if (from.findPatron(100) && to.findPatron(100))
	{
		//ask for money
		//withdrawal from and deposit to (new functions)
	}
}

void bigRead()
{
	//read the next line of the file
	//find the file whose title matches the string
	//read that file into that bank object (new read function)
}

void bigSave()
{
	//save all bank objects into a file, returning the name of the file (modify save)
	//
}
//--------------------

/* int main()
{
	Patron p("h",1,1);
	Chrono::Date d;
	Chrono::Time now;
	Transaction tr(p,d,now,"Deposit",11);
	BankIntl intl;
	intl.menu();
} */