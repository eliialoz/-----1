#include<iostream>
#include "Clock.h"
#include "Account.h"




enum Action {
    STOP,
    BALANCE,
    WITHDRAW,
    DEPOSIT,
    SUM_DEPOSIT,
    SUM_WITHDRAW
};

Action menu() {
    cout << endl;
    cout << "enter 1 to get account balance" << endl;
    cout << "enter 2 to withdraw money" << endl;
    cout << "enter 3 to deposit money" << endl;
    cout << "enter 4 to see the sum of all withdraws" << endl;
    cout << "enter 5 to see the sum of all Deposits" << endl;
    cout << "enter 0 to stop" << endl;
    int x;
    cin >> x;
    return (Action)x;
}

int findAccount(Account* bank, int size) {
    unsigned int number, code;
    cout << "please enter account number: ";
    cin >> number;
    int i = 0;
    while (i < size && bank[i].getAccountNumber() != number) i++;
    if (i == size)
        throw "ERROR: no such account number!\n";
    cout << "please enter the code: ";
    cin >> code;
    if (bank[i].getCode() == code) return i;
    throw "ERROR: wrong code!\n";
}

void printTransaction(Account a, Action ac,const Clock& c) {
    cout << c << "\t";
    switch (ac) {
    case BALANCE:
        cout << "Account #: " << a.getAccountNumber() << "\t";
        cout << "balance: " << a.getBalance() << endl;
        break;
    case DEPOSIT:
    case WITHDRAW:
        cout << "Account #: " << a.getAccountNumber() << "\t";
        cout << "new balance: " << a.getBalance() << endl;
        break;
    case SUM_DEPOSIT:
        cout << "Sum of all deposits: " << Account::getSumDeposit() << endl;
        break;
    case SUM_WITHDRAW:
        cout << "Sum of all withdraws: " << Account::getSumWithdraw() << endl;
        break;
    }
}

void getBalance(Account* bank, int size, Clock& c) {
    int i = findAccount(bank, size);
    printTransaction(bank[i], BALANCE, c+=20);
}

void cashDeposit(Account* bank, int size, Clock& c) {
    int i = findAccount(bank, size);
    float amount;
    cout << "enter the amount of the check: ";
    cin >> amount;
    bank[i].deposit(amount);
   
    printTransaction(bank[i], DEPOSIT, c+=50);
}

void cashWithdraw(Account* bank, int size, Clock& c) {
    int i = findAccount(bank, size);
    float amount;
    cout << "enter the amount of money to withdraw: ";
    cin >> amount;
    bank[i].withdraw(amount);
    printTransaction(bank[i], WITHDRAW, c += 30);
}

int main() {
    Clock clock(8);
    Account bank[10];

    cout << "enter account number and code for 10 accounts:\n";
    for (int i = 0; i < 10; i++) {
        try {
            cin >> bank[i];
            for (int j = 0; j < i; j++)
                if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
                    throw "ERROR: account number must be unique!\n";
              
               
            if (i < 9)
            cout << "enter account number and code:" << endl;
        }
        catch (const char* msg) {
            cin.clear();//if the number is greater than what int could contain
            cout << clock << '\t' << msg;
            i--;
        }
    }
    
        Action ac = menu();
        while (ac) {
            try {
                switch (ac) {
                case BALANCE:
                    getBalance(bank, 10, ++clock);
                    break;
                case WITHDRAW:
                    cashWithdraw(bank, 10, ++clock);
                    break;
                case DEPOSIT:
                    clock++;
                    cashDeposit(bank, 10, clock);
                    break;
                case SUM_DEPOSIT:
                    clock += 60;
                    printTransaction(bank[0], SUM_DEPOSIT, ++clock);
                    break;
                case SUM_WITHDRAW:
                    clock += 60;
                    printTransaction(bank[0], SUM_WITHDRAW, ++clock);
                    break;
                }

                ac = menu();
            }
            catch (const char* msg) {
                cout << clock << endl;
                cout << msg << endl;
            }

        }
   

    return 0;
}

