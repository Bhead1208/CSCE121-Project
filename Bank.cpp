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
/*
	Function Deposit 
	Asks for a patron ID and, if they exist, create a transaction object with the
	attributes the patron object (reference) and "Deposit."
	@param vactor of integers
	@return void returns nothing
*/
void Bank::Deposit(Patron namePatron, vector<int> vec){
	int num;
	bool valid;	
	cout<<"Enter Id"<<endl;
	cin>>num;
	
	// for loop checks trough vector of id's to see if id exists
	for(int i=0 ; i<vec.size(); i++){
		if(num == vec[i]){
			valid = true;
			break;
		}
	}
	if(valid){
		// getting data from user to create time object
		cout<<"Enter Time"<<endl;
		cout<<"Enter Hour"<<endl; 
		cin>> int hou; // stroes hour
		cout<<"Enter Minute"<<endl;
		cin>> int min;// stores minute
		cout<<"Enter Second"<<endl;
		cin>> int sec;// stores second
		Time timeObj(hou,min,sec);//might have built object incorrectly come back and check
		cout<<"Enter Date"<<endl;
		cout<<"Enter Day"<<endl; 
		cin>> int dd; // stroes hour
		cout<<"Enter Month"<<endl;
		cin>> int mm;// stores minute
		cout<<"Enter Year"<<endl;
		cin>> int yy;// stores second
		Date dateObj(yy,Date::Month(mm),dd); // might have built object incorrectly come back and check
		cout<<"Enter Currency Type"<<endl;
		cin>> string strCurrency;
		cout<<"Enter Amount"<<endl;
		cin>> double amountMon;
			
		Transaction transObj(namePatron,dateObj,timeObj,strCurrency,amountMon);
	}
	else cout<<" NO MATCHING ACCOUNT FOR THIS ID "<<endl;
}

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

void get_Transaction(Transaction t)
{
    for (int i=0; i<t.size();i++){
        cout << t[i] << endl;
    }
}

void get_Patrons(Patron p)
{
    for (int i=0; i<p.size();i++){
        cout << p[i] << endl;
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

