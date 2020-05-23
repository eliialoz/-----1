#include"Clock.h"

//construtor
Clock::Clock(int h, int m , int s) {
	if ((h < 0) || (h > 24))
		hour = 0;
	else
		hour = h;
	if ((m < 0) || (m > 60))
		minute = 0;
	else
		minute = m;
	if ((s < 0) || (s > 60))
		second = 0;
	else
		second = s;
}
//set function
void Clock:: setHour(int h) {
	hour = h;
}
void Clock::setMinute(int m) {
	minute = m;
}
void Clock::setSecond(int s) {
	second = s;
}
//get function
int Clock::getHour()const {
	return hour;
}
int Clock::getMinute()const {
	return minute;
}
int Clock::getSecond()const {
	return second;
}
//operators overloading
Clock& Clock:: operator += (int s) {
	int sec = second + s;
	if (sec > 60)
		second = sec % 60;
	else
		second = sec;

	int min = minute + sec / 60;
	if (min > 60)
		minute = min % 60;
	else
		minute = min;

	int hou = hour + min / 60;
	if (hou > 24)
		hour = hou % 24;
	else
		hour = hou;

	return *this;
}
Clock& Clock::operator ++ () {
	int sec = second + 1;
	if (sec > 60)
		second = sec % 60;
	else
		second = sec;

	int min = minute + sec / 60;
	if (min > 60)
		minute = min % 60;
	else
		minute = min;

	int hou = hour + min / 60;
	if (hou > 24)
		hour = hou % 24;
	else
		hour = hou;

	return *this;
}
 Clock Clock::operator ++ (int) {
	Clock temp = *this;
	int sec = second + 1;
	if (sec > 60)
		second = sec % 60;
	else
		second = sec;

	int min = minute + sec / 60;
	if (min > 60)
		minute = min % 60;
	else
		minute = min;

	int hou = hour + min / 60;
	if (hou > 24)
		hour = hou % 24;
	else
		hour = hou;
	return temp;
}
ostream& operator << (ostream& out,const Clock& c1) {
	if (c1.getHour() < 10)
		out << "0" << c1.getHour() << ":";
	else
		out << c1.getHour() << ":";

	if (c1.getMinute() < 10)
		out << "0" << c1.getMinute() << ":";
	else
		out << c1.getMinute() << ":";

	if (c1.getSecond() < 10)
		out << "0" << c1.getSecond();
	else
		out << c1.getSecond();

	return out;
}
 istream& operator >> (istream& in, Clock& c1) {
	in >> c1.hour >> c1.minute >> c1.second;

	if (c1.hour > 24)
		throw "Invalid time - more than 24 hours./n";
	if (c1.hour < 0)
		throw "Invalid time - negative number of hours./n";
	if (c1.minute > 60)
		throw "Invalid time - more than 60 minutes./n";
	if (c1.minute < 0)
		throw "Invalid time - negative number of minutes./n";
	if (c1.second > 60)
		throw "Invalid time - more than 60 seconds./n";
	if (c1.second < 0)
		throw "Invalid time - negative number of seconds./n";

	return in;
}



