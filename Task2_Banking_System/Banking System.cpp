#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ---------- Transaction Class ----------
class Transaction {
public:
    string type;      // Deposit, Withdraw, Transfer
    double amount;
    double balanceAfter;

    Transaction(string t, double amt, double balAfter) {
        type = t;
        amount = amt;
        balanceAfter = balAfter;
    }

    void display() {
        cout << type << " | Amount: " << amount
             << " | Balance After: " << balanceAfter << endl;
    }
};

// ---------- Account Class ----------
class Account {
public:
    int accNumber;
    double balance;
    vector<Transaction> history;

    Account(int accNo, double initialBalance = 0) {
        accNumber = accNo;
        balance = initialBalance;
    }

    bool deposit(double amount) {
        if (amount <= 0) {
            cout << "Error: Deposit amount must be positive.\n";
            return false;
        }
        balance += amount;
        history.push_back(Transaction("Deposit", amount, balance));
        cout << "Deposit successful. New Balance: " << balance << endl;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Withdrawal amount must be positive.\n";
            return false;
        }
        if (amount > balance) {
            cout << "Error: Insufficient balance.\n";
            return false;
        }
        balance -= amount;
        history.push_back(Transaction("Withdraw", amount, balance));
        cout << "Withdrawal successful. New Balance: " << balance << endl;
        return true;
    }

    void showBalance() {
        cout << "Account #" << accNumber << " | Balance: " << balance << endl;
    }

    void showRecentTransactions(int count = 5) {
        cout << "\nRecent Transactions for Account #" << accNumber << ":\n";
        if (history.empty()) {
            cout << "No transactions yet.\n";
            return;
        }
        int start = max(0, (int)history.size() - count);
        for (int i = start; i < (int)history.size(); i++) {
            history[i].display();
        }
    }
};

// ---------- Customer Class ----------
class Customer {
public:
    int custId;
    string name;
    Account account;

    Customer(int id, string n, int accNo) : account(accNo) {
        custId = id;
        name = n;
    }

    void showInfo() {
        cout << "\nCustomer ID: " << custId << " | Name: " << name << endl;
        account.showBalance();
    }
};

// ---------- Bank Management ----------
class Bank {
    vector<Customer> customers;
    int nextCustId = 1;
    int nextAccNo = 1001;

public:
    Bank() {
        customers.reserve(100); // prevents pointer invalidation up to 100 elements
    }

    Customer* createCustomer(string name) {
        Customer newCust(nextCustId++, name, nextAccNo++);
        customers.push_back(newCust);
        cout << "Customer created! ID: " << newCust.custId
             << " | Account No: " << newCust.account.accNumber << endl;
        return &customers.back();
    }

    Customer* findByAccNo(int accNo) {
        for (Customer& c : customers) {
            if (c.account.accNumber == accNo) {
                return &c;
            }
        }
        return nullptr;
    }

    void deposit(int accNo, double amount) {
        Customer* c = findByAccNo(accNo);
        if (!c) { cout << "Error: Account not found.\n"; return; }
        c->account.deposit(amount);
    }

    void withdraw(int accNo, double amount) {
        Customer* c = findByAccNo(accNo);
        if (!c) { cout << "Error: Account not found.\n"; return; }
        c->account.withdraw(amount);
    }

    void transfer(int fromAcc, int toAcc, double amount) {
        if (fromAcc == toAcc) {
            cout << "Error: Cannot transfer to the same account.\n";
            return;
        }
        if (amount <= 0) {
            cout << "Error: Transfer amount must be positive.\n";
            return;
        }

        Customer* from = findByAccNo(fromAcc);
        Customer* to = findByAccNo(toAcc);

        if (!from || !to) { cout << "Error: One or both accounts not found.\n"; return; }
        if (amount > from->account.balance) { cout << "Error: Insufficient balance.\n"; return; }

        from->account.balance -= amount;
        from->account.history.push_back(Transaction("Transfer-Out", amount, from->account.balance));

        to->account.balance += amount;
        to->account.history.push_back(Transaction("Transfer-In", amount, to->account.balance));

        cout << "Transfer successful: " << amount << " sent from Acc#"
             << fromAcc << " to Acc#" << toAcc << endl;
    }

    void showAccountInfo(int accNo) {
        Customer* c = findByAccNo(accNo);
        if (!c) { cout << "Error: Account not found.\n"; return; }
        c->showInfo();
        c->account.showRecentTransactions();
    }
};

// ---------- Main Menu ----------
int main() {
    Bank bank;
    int choice;

    do {
        cout << "\n===== Banking System =====\n";
        cout << "1. Create Customer\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer Funds\n";
        cout << "5. View Account Info\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }

        if (choice == 1) {
            string name;
            cout << "Enter customer name: ";
            cin.ignore();
            getline(cin, name);
            bank.createCustomer(name);
        }
        else if (choice == 2) {
            int accNo; double amt;
            cout << "Enter account number: "; cin >> accNo;
            cout << "Enter amount: "; cin >> amt;
            bank.deposit(accNo, amt);
        }
        else if (choice == 3) {
            int accNo; double amt;
            cout << "Enter account number: "; cin >> accNo;
            cout << "Enter amount: "; cin >> amt;
            bank.withdraw(accNo, amt);
        }
        else if (choice == 4) {
            int fromAcc, toAcc; double amt;
            cout << "From account: "; cin >> fromAcc;
            cout << "To account: "; cin >> toAcc;
            cout << "Amount: "; cin >> amt;
            bank.transfer(fromAcc, toAcc, amt);
        }
        else if (choice == 5) {
            int accNo;
            cout << "Enter account number: "; cin >> accNo;
            bank.showAccountInfo(accNo);
        }
        else if (choice == 6) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
