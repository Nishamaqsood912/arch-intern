#include <iostream>

using namespace std;

class ATM {
private:
    double balance;

public:
    ATM(double initialBalance = 0.0) {
        balance = initialBalance;
    }

    void checkBalance() const {
        cout << "Current Balance: $" << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful." << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        }
        else if (amount > balance) {
            cout << "Insufficient funds." << endl;
        }
        else {
            balance -= amount;
            cout << "Withdrawal successful." << endl;
        }
    }
};

int main() {
    ATM userAccount(1000.0);  
    int choice;
    double amount;

    while (true) {
        cout << "\nATM Menu " << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Check if input fails
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                userAccount.checkBalance();
                break;

            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                userAccount.deposit(amount);
                break;

            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                userAccount.withdraw(amount);
                break;

            case 4:
                cout << "Thank you for using the ATM!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
