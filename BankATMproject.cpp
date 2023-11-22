#include <iostream>
using namespace std;

class BankATM
{
private:
    string accountNumber;
    int pin;
    double balance;

public:
    BankATM(string accNum, int p, double bal)
    {
        accountNumber = accNum;
        pin = p;
        balance = bal;
    }

    bool checkPIN(int p)
    {
        return (p == pin);
    }

    void displayBalance()
    {
        cout << "Your balance is: $" << balance << endl;
    }

    void withdraw(double amount)
    {
        if (amount <= balance && amount > 0)
        {
            balance -= amount;
            cout << "Withdrawal successful. Remaining balance: $" << balance << endl;
        }
        else
        {
            cout << "Invalid amount or insufficient balance." << endl;
        }
    }

    void changePIN(int newPin)
    {
        pin = newPin;
        cout << "PIN changed successfully." << endl;
    }
};

int main()
{
    BankATM account("123456789", 1234, 1000.0);

    int choice;
    int enteredPIN;

    cout << "Welcome to the Bank ATM Simulation" << endl;
    cout << "Enter your PIN: ";
    cin >> enteredPIN;

    if (account.checkPIN(enteredPIN))
    {
        do
        {
            cout << "\nMenu:" << endl;
            cout << "1. Balance Inquiry" << endl;
            cout << "2. Cash Withdrawal" << endl;
            cout << "3. Change PIN" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                account.displayBalance();
                break;
            case 2:
                double withdrawalAmount;
                cout << "Enter withdrawal amount: $";
                cin >> withdrawalAmount;
                account.withdraw(withdrawalAmount);
                break;
            case 3:
                int newPIN;
                cout << "Enter new PIN: ";
                cin >> newPIN;
                account.changePIN(newPIN);
                break;
            case 4:
                cout << "Thank you for using our ATM. Have a nice day!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 4);
    }
    else
    {
        cout << "Invalid PIN. Please try again." << endl;
    }

    return 0;
}
