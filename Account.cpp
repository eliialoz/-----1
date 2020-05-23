#include"Account.h";

//construtor
Account::Account(int a, int c, double b) {
	acountNumber = a;
	code = c;
	balance = b;
}
int Account::sumWithdraw;
 int Account:: sumDeposit;
 //set function
 void Account::setBalance(int b) {
	 balance = b;
 }
 //get function
int Account:: getBalance() {
	return balance;
}
int Account::getAccountNumber() {
	return acountNumber;
}
int Account::getCode() {
	return code;
}
int  Account::getSumWithdraw() {
	return sumWithdraw;
}
int Account::getSumDeposit() {
	return sumDeposit;
}
//operators overloading
istream& operator>> (istream& in, Account& A1)
{
	in >> A1.acountNumber >> A1.code;
	if (A1.code > 10000 || A1.code < 1000)
		throw "ERROR: code must be of 4 digits!\n";

	return in;
}
//the function checks if the withdrawal is legal
void Account::withdraw(int nis) {
	int maxPull = 2500;
	int maxMinus = -6000;
	if ((nis <= maxPull) && (balance - nis >= maxMinus)) {
		balance -= nis;
		sumWithdraw-=nis;
	}
	else if (nis > maxPull)
		throw "ERROR: cannot withdraw more than 2500 NIS!\n";
	else
		throw "ERROR: cannot have less than - 6000 NIS!\n";
}
//the function checks if the money deposit is legal
void Account:: deposit(int dep) {
	if (dep <= 10000) {
		balance += dep;
		sumDeposit+=dep;
	}
	else
		throw "ERROR: cannot deposit more than 10000 NIS!\n";
}

