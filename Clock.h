#ifndef CLOCK_H
#define CLOCK_H

#include<iostream>
using namespace std;

class Clock {
	int hour;
	int minute;
	int second;
public:
	//construtor
	Clock():hour(0), minute(0),second(0){}
	Clock(int h, int m = 0, int s = 0);
	
	//set function
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);
	//get function
	int getHour()const;
	int getMinute()const;
	int getSecond()const;

	//operators overloading
	 Clock& operator +=(int s);
	 Clock& operator ++();
	 Clock operator ++ (int);
	 friend ostream& operator << (ostream& out,const Clock& c1); 
	 friend istream& operator >> (istream& in, Clock& c1);
		
};
ostream& operator << (ostream& out,const Clock& c1);
istream& operator >> (istream& in, Clock& c1);
#endif