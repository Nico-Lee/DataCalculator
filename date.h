#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year, int month, int day);
	~Date();
	Date(const Date& a);
	void ShowDate();
	bool operator==(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);


	Date operator+ (int day);
	Date& operator+= (int day);
	Date operator- (int day);
	Date& operator-= (int day);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	int operator-(const Date& d);
	friend ostream* operator<<(ostream* out, const Date &d);

private:
	int GetMonthDay(int year, int month);
	bool IsLeapYear(int year);
	int _year;
	int _month;
	int _day;
};
