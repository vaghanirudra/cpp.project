#include <iostream>
#include <string>

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
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
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
    
    SavingsAccount s1(101, "Rudra", 5000, 5);

    CheckingAccount c1(102, "Meet", 8000, 2000);

    FixedDepositAccount f1(103, "Yash", 10000, 12, 7);

    int choice;
    double amount;

    do
    {
        cout << "\n========== BANKING SYSTEM ==========\n";
        cout << "1. Savings Account\n";
        cout << "2. Checking Account\n";
        cout << "3. Fixed Deposit Account\n";
        cout << "4. Polymorphism Demo\n";
        cout << "0. Exit\n";
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
                cout << "1. Deposit\n";
                cout << "2. Withdraw\n";
                cout << "3. Display Info\n";
                cout << "4. Calculate Interest\n";
                cout << "0. Back\n";
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
                cout << "1. Deposit\n";
                cout << "2. Withdraw\n";
                cout << "3. Display Info\n";
                cout << "4. Check Overdraft\n";
                cout << "0. Back\n";
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
                cout << "1. Deposit\n";
                cout << "2. Withdraw\n";
                cout << "3. Display Info\n";
                cout << "4. Calculate Interest\n";
                cout << "0. Back\n";
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