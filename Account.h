#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
using namespace std;

class Account {
	int acountNumber;
	int code;
	int balance = 0;
	
public:
	static int sumWithdraw;
	static int sumDeposit;
	//construtor
	Account() :acountNumber(0), code(0), balance(0){}
	Account(int a, int c, double b);
	//set function
	void setBalance(int b);
	//get function
	int getBalance();
	int getAccountNumber();
	int getCode();
	static int getSumWithdraw();
	static int getSumDeposit();
	//operators overloading
	friend istream& operator>> (istream& in, Account& A1);
	//the function checks if the withdrawal is legal
	void withdraw(int nis);
	//the function checks if the money deposit is legal
	void deposit(int dep);
};
istream& operator>> (istream& in, Account& A1);
#endif