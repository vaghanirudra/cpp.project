#include<iostream>

using namespace std;

class BankAccount
{
protected:
    int accountNumber;
    string accountHolderName;

private:
    double balance;

public:

    BankAccount(int accNo, string name, double bal)
    {
        accountNumber=accNo;
        accountHolderName=name;
        balance=bal;
    }

    virtual void deposit(double amount)
    {
        balance += amount;
        cout << "Amount Deposited Successfully!\n";
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal Successful!\n";
        }
        else
        {
            cout << "Insufficient Balance!\n";
        }
    }

    double getBalance()
    {
        return balance;
    }

protected:
    
    void setBalance(double bal)
    {
        balance = bal;
    }

public:

    virtual void calculateInterest()
    {
        cout << "No Interest Calculation for Base Account\n";
}
    virtual void displayAccountInfo()
    {
        cout << "\n===== Account Details =====\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Balance        : " << getBalance() << endl;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal)
    {
        interestRate = rate;
    }

    void calculateInterest() override
    {
        double interest = getBalance() * interestRate / 100;

        cout << "Savings Account Interest : " << interest << endl;
    }

    void displayAccountInfo() override
    {
        BankAccount::displayAccountInfo();
        cout << "Account Type   : Savings Account\n";
        cout << "Interest Rate  : " << interestRate << "%\n";
    }
};


class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal)
    {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override
    {
        if (amount <= (getBalance() + overdraftLimit))
        {
            setBalance(getBalance() - amount);
            cout << "Withdrawal Successful!\n";
        }
        else
        {
            cout << "Overdraft Limit Exceeded!\n";
        }
    }

    void checkOverdraft()
    {
        cout << "Overdraft Limit : " << overdraftLimit << endl;
    }

    void displayAccountInfo() override
    {
        BankAccount::displayAccountInfo();
        cout << "Account Type   : Checking Account\n";
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
private:
    int term;
    double interestRate;

public:
    FixedDepositAccount(int accNo, string name, double bal,
                        int t, double rate)
        : BankAccount(accNo, name, bal)
    {
        term = t;
        interestRate = rate;
    }

    void calculateInterest() override
    {
        double interest =
            (getBalance() * interestRate * term) / (100 * 12);

        cout << "Fixed Deposit Interest : " << interest << endl;
    }

    void displayAccountInfo() override
    {
        BankAccount::displayAccountInfo();
        cout << "Account Type   : Fixed Deposit Account\n";
        cout << "Term (Months)  : " << term << endl;
        cout << "Interest Rate  : " << interestRate << "%\n";
    }
};

int main()
{
    
    SavingsAccount s1(200, "Rudra", 5000, 5);

    CheckingAccount c1(300, "Rudra", 8000, 2000);

    FixedDepositAccount f1(500, "Rudra", 10000, 12, 7);

    int choice;
    double amount;

    do
    {
        cout << "\n========== BANKING SYSTEM ==========\n";
        cout << "0. Savings Account\n";
        cout << "1. Checking Account\n";
        cout << "2. Fixed Deposit Account\n";
        cout << "3. Polymorphism Demo\n";
        cout << "4. Exit\n";
        cout << "Enter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int ch;

            do
            {
                cout << "\n--- Savings Account Menu ---\n";
                cout << "0. Deposit\n";
                cout << "1. Withdraw\n";
                cout << "2. Display Info\n";
                cout << "3. Calculate Interest\n";
                cout << "4. Back\n";
                cout << "Enter Choice : ";
                cin >> ch;

                switch (ch)
                {
                case 1:
                    cout << "Enter Amount : ";
                    cin >> amount;
                    s1.deposit(amount);
                    break;

                case 2:
                    cout << "Enter Amount : ";
                    cin >> amount;
                    s1.withdraw(amount);
                    break;

                case 3:
                    s1.displayAccountInfo();
                    break;

                case 4:
                    s1.calculateInterest();
                    break;
                }

            } while (ch != 0);

            break;
        }

        case 2:
        {
            int ch;

            do
            {
                cout << "\n--- Checking Account Menu ---\n";
                cout << "0. Deposit\n";
                cout << "1. Withdraw\n";
                cout << "2. Display Info\n";
                cout << "3. Check Overdraft\n";
                cout << "4. Back\n";
                cout << "Enter Choice : ";
                cin >> ch;

                switch (ch)
                {
                case 1:
                    cout << "Enter Amount : ";
                    cin >> amount;
                    c1.deposit(amount);
                    break;

                case 2:
                    cout << "Enter Amount : ";
                    cin >> amount;
                    c1.withdraw(amount);
                    break;

                case 3:
                    c1.displayAccountInfo();
                    break;

                case 4:
                    c1.checkOverdraft();
                    break;
                }

            } while (ch != 0);

            break;
        }

        case 3:
        {
            int ch;

            do
            {
                cout << "\n--- Fixed Deposit Menu ---\n";
                cout << "0. Deposit\n";
                cout << "1. Withdraw\n";
                cout << "2. Display Info\n";
                cout << "3. Calculate Interest\n";
                cout << "4. Back\n";
                cout << "Enter Choice : ";
                cin >> ch;

                switch (ch)
                {
                case 1:
                    cout << "Enter Amount : ";
                    cin >> amount;
                    f1.deposit(amount);
                    break;

                case 2:
                    cout << "Enter Amount : ";
                    cin >> amount;
                    f1.withdraw(amount);
                    break;

                case 3:
                    f1.displayAccountInfo();
                    break;

                case 4:
                    f1.calculateInterest();
                    break;
                }

            } while (ch != 0);

            break;
        }

        case 4:
        {
            cout << "\n===== POLYMORPHISM DEMO =====\n";

            BankAccount *ptr;

            ptr = &s1;
            ptr->calculateInterest();

            ptr = &f1;
            ptr->calculateInterest();

            break;
        }

        case 0:
            cout << "Thank You for Using Banking System!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 0);
}

/*
output
	
========== BANKING SYSTEM ==========
1. Savings Account
2. Checking Account
3. Fixed Deposit Account
4. Polymorphism Demo
0. Exit
Enter Choice : 1

--- Savings Account Menu ---
1. Deposit
2. Withdraw
3. Display Info
4. Calculate Interest
0. Back
Enter Choice : 1
Enter Amount : 3000
Amount Deposited Successfully!

--- Savings Account Menu ---
1. Deposit
2. Withdraw
3. Display Info
4. Calculate Interest
0. Back
Enter Choice : 2
Enter Amount : 3000
Withdrawal Successful!

--- Savings Account Menu ---
1. Deposit
2. Withdraw
3. Display Info
4. Calculate Interest
0. Back
Enter Choice : 3

===== Account Details =====
Account Number : 101
Account Holder : Rudra
Balance        : 5000
Account Type   : Savings Account
Interest Rate  : 5%

--- Savings Account Menu ---
1. Deposit
2. Withdraw
3. Display Info
4. Calculate Interest
0. Back
Enter Choice : 4
Savings Account Interest : 250

--- Savings Account Menu ---
1. Deposit
2. Withdraw
3. Display Info
4. Calculate Interest
0. Back
Enter Choice :
0

========== BANKING SYSTEM ==========
1. Savings Account
2. Checking Account
3. Fixed Deposit Account
4. Polymorphism Demo
0. Exit
Enter Choice : 2

--- Checking Account Menu ---
1. Deposit
2. Withdraw
3. Display Info
4. Check Overdraft
0. Back
Enter Choice : 1
Enter Amount : 3000
Amount Deposited Successfully!

--- Checking Account Menu ---
1. Deposit
2. Withdraw
3. Display Info
4. Check Overdraft
0. Back
Enter Choice : 1
Enter Amount : 3000
Amount Deposited Successfully!

--- Checking Account Menu ---
1. Deposit
2. Withdraw
3. Display Info
4. Check Overdraft
0. Back
Enter Choice : 2
Enter Amount : 6000
Withdrawal Successful!

--- Checking Account Menu ---
1. Deposit
2. Withdraw
3. Display Info
4. Check Overdraft
0. Back
Enter Choice : 3

===== Account Details =====
Account Number : 102
Account Holder : Meet
Balance        : 8000
Account Type   : Checking Account
Overdraft Limit: 2000

--- Checking Account Menu ---
1. Deposit
2. Withdraw
3. Display Info
4. Check Overdraft
0. Back
Enter Choice : 4
Overdraft Limit : 2000

--- Checking Account Menu ---
1. Deposit
2. Withdraw
3. Display Info
4. Check Overdraft
0. Back
Enter Choice : 0

========== BANKING SYSTEM ==========
1. Savings Account
2. Checking Account
3. Fixed Deposit Account
4. Polymorphism Demo
0. Exit
Enter Choice : 3

--- Fixed Deposit Menu ---
1. Deposit
2. Withdraw
3. Display Info
4. Calculate Interest
0. Back
Enter Choice : 1
Enter Amount : 3000
Amount Deposited Successfully!

--- Fixed Deposit Menu ---
1. Deposit
2. Withdraw
3. Display Info
4. Calculate Interest
0. Back
Enter Choice : 2
Enter Amount : 3000
Withdrawal Successful!

--- Fixed Deposit Menu ---
1. Deposit
2. Withdraw
3. Display Info
4. Calculate Interest
0. Back
Enter Choice : 3

===== Account Details =====
Account Number : 103
Account Holder : Yash
Balance        : 10000
Account Type   : Fixed Deposit Account
Term (Months)  : 12
Interest Rate  : 7%

--- Fixed Deposit Menu ---
1. Deposit
2. Withdraw
3. Display Info
4. Calculate Interest
0. Back
Enter Choice : 4
Fixed Deposit Interest : 700

--- Fixed Deposit Menu ---
1. Deposit
2. Withdraw
3. Display Info
4. Calculate Interest
0. Back
Enter Choice : 0

========== BANKING SYSTEM ==========
1. Savings Account
2. Checking Account
3. Fixed Deposit Account
4. Polymorphism Demo
0. Exit
Enter Choice : 4

===== POLYMORPHISM DEMO =====
Savings Account Interest : 250
Fixed Deposit Interest : 700

========== BANKING SYSTEM ==========
1. Savings Account
2. Checking Account
3. Fixed Deposit Account
4. Polymorphism Demo
0. Exit
Enter Choice : 0
Thank You for Using Banking System!

--------------------------------
Process exited after 286.5 seconds with return value 0
Press any key to continue . .  
*/
