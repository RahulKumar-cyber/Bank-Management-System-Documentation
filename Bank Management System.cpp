#include <iostream>
#include <vector>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accountNumber, string accountHolderName, double balance)
    {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance. Withdrawal failed." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        }
    }

    int getAccountNumber()
    {
        return accountNumber;
    }

    string getAccountHolderName()
    {
        return accountHolderName;
    }

    double getBalance()
    {
        return balance;
    }
};

class Bank
{
private:
    vector<BankAccount> accounts;

public:
    void addAccount(BankAccount account)
    {
        accounts.push_back(account);
        cout << "Account added successfully." << endl;
    }

    void removeAccount(int accountNumber)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].getAccountNumber() == accountNumber)
            {
                accounts.erase(accounts.begin() + i);
                cout << "Account removed successfully." << endl;
                return;
            }
        }
        cout << "Account not found. Removal failed." << endl;
    }

    BankAccount *getAccount(int accountNumber)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].getAccountNumber() == accountNumber)
            {
                return &accounts[i];
            }
        }
        return NULL;
    }
};

int main()
{
    Bank bank;

    while (true)
    {
        int choice;
        cout << "1. Add account" << endl;
        cout << "2. Remove account" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Check balance" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int accountNumber;
            string accountHolderName;
            double balance;
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter account holder name: ";
            cin >> accountHolderName;
            cout << "Enter balance: ";
            cin >> balance;
            BankAccount account(accountNumber, accountHolderName, balance);
            bank.addAccount(account);
        }
        else if (choice == 2)
        {
            int accountNumber;
            cout << "Enter account number: ";
            cin >> accountNumber;
            bank.removeAccount(accountNumber);
        }
        else if (choice == 3)
        {
            int accountNumber;
            double amount;
            cout << "Enter account number: ";
            cin >> accountNumber;
            BankAccount *account = bank.getAccount(accountNumber);
            if (account != NULL)
            {
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account->deposit(amount);
            }
            else
            {
                cout << "Account not found. Deposit failed." << endl;
            }
        }
        else if (choice == 4)
        {
            int accountNumber;
            double amount;
            cout << "Enter account number: ";
            cin >> accountNumber;
            BankAccount *account = bank.getAccount(accountNumber);
            if (account != NULL)
            {
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account->withdraw(amount);
            }
            else
            {
                cout << "Account not found. Withdrawal failed." << endl;
            }
        }
        else if (choice == 5)
        {
            int accountNumber;
            cout << "Enter account number: ";
            cin >> accountNumber;
            BankAccount *account = bank.getAccount(accountNumber);
            if (account != NULL)
            {
                cout << "Balance: " << account->getBalance() << endl;
            }
            else
            {
                cout << "Account not found. Balance check failed." << endl;
            }
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}

