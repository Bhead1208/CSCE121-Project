//
//  main.cpp
//  Project
//
//  Created by Aadhav Chandran on 11/3/16.
//  Copyright © 2016 Aadhav Chandran. All rights reserved.
//
#include "std_lib_facilities_4.h"
#include "Chrono.h"

struct Currency{
public:
    Currency(string type,double rate)
        :currency_type(type),exchange_rate(rate)
    {}
    
    string getCurrency_type()
    {
        return currency_type;
    }
    
    double getexchange_rate()
    {
        return exchange_rate;
    }
    
private:
    string currency_type;
    double exchange_rate;
};

struct Transaction{
public:
    
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
    
    
private:
    Patron::Patron customer;
    Chrono::Date transaction_date;
    Chrono::Time transaction_time;
    string transaction_type;
    double transaction_amount;
    
};

int main()
{
    
}