#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <map>

#define MIN_BALANCE 500

using namespace std;

class InsufficientFunds:public exception
{

};

class Account
{
    friend ofstream &operator<<(ofstream &os,Account &acc);
    friend ostream &operator<<(ostream &os,Account &acc);
    friend ifstream &operator>>(ifstream &os,Account &acc);
private:
    long accountNumber;
    string firstName;
    string lastName;
    float balance;
    static long NextAccountNumber;
public:
    Account(){};
    Account(string fname,string lname,float balance);
    long Get_Account_No(){return accountNumber;}
    string Get_FirstName(){return firstName;}
    string Get_LastName(){return lastName;}
    float Get_Balance(){return balance;}
    static void SetLastAccountNumber(long accountNumber);
    static long GetLastAccountNumber();

    void Deposit(float);
    void WithDraw(float);
};
long Account::NextAccountNumber = 0;


class Bank
{
private:
    map<long,Account> accounts;
public:
    Bank();
    Account OpenAccount(string fname,string lname,float balance);
    Account BalanceEnquiry(long accountNumber);
    Account Deposit(long accountNumber,float amount);
    Account WithDraw(long accountNumber,float amount);
    void CloseAccount(long accountNumber);
    void DisplayAccounts();
    ~Bank();
};

int main()
{
    Bank bank;
    Account account;

    int selection;
    string fname{}, lname{};
    long accountNumber;
    float balance{};
    float amount{};
    cout << setw(20)<<left<< "***Banking System***" << endl;
    do
    {
        cout << "\n\tSelect one option below:";
        cout << "\n\t1 Open an Account";
        cout << "\n\t2 Balance Inquiry";
        cout << "\n\t3 Deposit";
        cout << "\n\t4 Withdrawal";
        cout << "\n\t5 Close an Account";
        cout << "\n\t6 Show All Accounts";
        cout << "\n\t7 Quit";
        cout << "\nEnter your choice: ";
        cin >> selection;
        switch (selection)
        {
         case 1:
             cout << "Enter First Name: ";
             cin >> fname;
             cout << "Enter Last Name: ";
             cin >> lname;
             cout << "Enter Initial Balance: ";
             cin >> balance;
             account = bank.OpenAccount (fname, lname, balance);
             cout << endl << "Congratulation Account is Created" << endl;
             cout << account;
             break;

         case 2:
             cout << "Enter Account Number:";
             cin >> accountNumber;
             account = bank.BalanceEnquiry(accountNumber);
             cout << endl << "Your Account Details" << endl;
             cout << account;
             break;

         case 3:
             cout << "Enter Account Number:";
             cin >> accountNumber;
             cout << "Enter Balance:";
             cin >> amount;
             account = bank.Deposit(accountNumber, amount);
             cout << endl << "Amount is Deposited" << endl;
             cout << account;
             break;

         case 4:
             cout << "Enter Account Number:";
             cin >> accountNumber;
             cout << "Enter Balance:";
             cin >> amount;
             account = bank.WithDraw(accountNumber, amount);
             cout << endl << "Amount Withdrawn" << endl;
             cout << account;
             break;

         case 5:
             cout << "Enter Account Number:";
             cin >> accountNumber;
             bank.CloseAccount (accountNumber);
             cout << endl << "Account is Closed" << endl;
             cout << account;

         case 6:
             bank.DisplayAccounts();
             break;

         case 7:
             break;

         default:
             cout << "\nEnter correct choice";
             exit (0);
        }
    }
    while (selection != 7);

    return 0;
}
Account::Account(string fname,string lname,float balance)
:firstName{fname},lastName{lname},balance{balance}
{
    NextAccountNumber++;
    accountNumber = NextAccountNumber;
}

void Account::SetLastAccountNumber(long accountNumber)
{
    NextAccountNumber = accountNumber;
}

long Account::GetLastAccountNumber()
{
    return NextAccountNumber;
}

void Account::Deposit(float amount)
{
    balance += amount;
}

void Account::WithDraw(float amount)
{
    if(balance-amount < MIN_BALANCE)
        throw InsufficientFunds();
    balance -= amount;
}

ofstream &operator<<(ofstream &os,Account &acc)
{
    os << acc.accountNumber << endl;
    os << acc.firstName << endl;
    os << acc.lastName << endl;
    os << acc.balance << endl;
    return  os;
}

ifstream &operator>>(ifstream &os,Account &acc)
{
    os>>acc.accountNumber;
    os>>acc.firstName;
    os>>acc.lastName;
    os>>acc.balance;
    return  os;
}

ostream &operator<<(ostream &os,Account &acc)
{
    os<<"First Name: "<<acc.Get_FirstName()<<endl;
    os<<"Last Name: "<<acc.Get_LastName()<<endl;
    os<<"Account Number: "<<acc.Get_Account_No()<<endl;
    os<<"Balance:"<<acc.Get_Balance()<<endl;
    return os;
}

Bank::Bank()
{
    Account account;
    ifstream file {"Bank.data"};
    if(!file)
        cerr<<"Error in Opening! File Not Found!!"<<endl;
    while(!file.eof())
    {
        file>>account;
        accounts.insert(pair<long,Account>(account.Get_Account_No(),account));
    }
    Account::SetLastAccountNumber(account.Get_Account_No());

    file.close();
}

Account Bank::OpenAccount(string fname,string lname,float balance)
{
    ofstream file;
    file.open("Bank.data",ios::trunc);
    Account account{fname,lname,balance};
    accounts.insert(pair<long,Account>(account.Get_Account_No(),account));

    map<long,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++)
        file<<itr->second;
    file.close();
    return account;
}
Account Bank::BalanceEnquiry(long accountNumber)
{
    map<long,Account>::iterator itr = accounts.find(accountNumber);
    return itr->second;
}
Account Bank::Deposit(long accountNumber,float amount)
{
    map<long,Account>::iterator itr = accounts.find(accountNumber);
    itr->second.Deposit(amount);
    return itr->second;
}
Account Bank::WithDraw(long accountNumber,float amount)
{
    map<long,Account>::iterator itr = accounts.find(accountNumber);
    itr->second.WithDraw(amount);
    return itr->second;
}
void Bank::CloseAccount(long accountNumber)
{
    map<long,Account>::iterator itr = accounts.find(accountNumber);
    cout<<"Account Deleted"<<itr->second;
    accounts.erase(accountNumber);
}
void Bank::DisplayAccounts()
{
    map<long,Account>::iterator itr;
    for(itr = accounts.begin();itr!=accounts.end();itr++)
        cout<<"Account"<<itr->first<<itr->second<<endl;
}
Bank::~Bank()
{
    ofstream file;
    file.open("Bank.data",ios::trunc);
    map<long,Account>::iterator itr;
    for(itr = accounts.begin();itr!=accounts.end();itr++)
        file<<itr->second;
    file.close();
}
