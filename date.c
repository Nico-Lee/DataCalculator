#include"date.h"



Date::Date(int year, int month, int day)
{
	if (year < 1900
		|| month>12 || month < 1
		|| day<1
		|| day>GetMonthDay(year, month))
	{
		cout << "初始化错误，日期重置为：1900-1-1" << endl;
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	else
	{
		_year = year;
		_month = month;
		_day = day;
	}
}
Date::~Date()
{
	cout << "调用析构函数" << endl;
}

Date::Date(const Date& a)
{
	cout << "调用拷贝构造函数" << endl;
	this->_year = a._year;
	this->_month = a._month;
	this->_day = a._day;
}
void Date::ShowDate()
{
	cout << _year << '-'
		<< _month << '-'
		<< _day << endl;
}


bool Date::operator==(const Date& d)
{
	return this->_year == d._year
		&&this->_month == d._month
		&&this->_day == d._day;
}
bool Date::operator<(const Date& d)
{
	if (this->_year>d._year)
		return false;
	else if (this->_year < d._year)
		return true;
	else
	{
		if (this->_month > d._month)
			return false;
		else if (this->_month < d._month)
			return true;
		else
		{
			if (this->_day > d._day||this->_day==d._day)
				return false;
			else
				return true;

		}
	}
}
bool Date::operator<=(const Date& d)
{
	return *this == d || *this < d;
}
bool Date::operator>(const Date& d)
{
	return !(*this <= d);
}
bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}

bool Date::IsLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0
		|| year % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Date::GetMonthDay(int year, int month)
{
	int MonthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = MonthArray[month];
	if (month == 2 && IsLeapYear(year))
	{
		day += 1;
	}
	return day;
}



Date Date::operator+ (int day)
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}
Date& Date::operator+= (int day)
{
	if (day<0)
	{
		return (*this -= (-day));
	}
	else
	{
		this->_day += day;
		while (this->_day > GetMonthDay(this->_year, this->_month))
		{
			this->_day -= GetMonthDay(this->_year, this->_month);
			if (this->_month < 12)
			{
				this->_month++;
			}
			else
			{
				this->_year++;
				this->_month %= 12;
			}
		}
		return *this;
	}
}
Date& Date::operator-= (int day)
{
	if (day < 0)
	{
		return (*this += (-day));
	}
	this->_day -= day;
	while (this->_day < 1)
	{
		this->_month --;
		if (this->_month < 1)
		{
			this->_year--;
			this->_month += 12;
			if (this->_year < 1)
			{
				exit(1);
			}
		}
		this->_day += GetMonthDay(this->_year, this->_month);
	}
	return *this;
}
Date& Date::operator++()
{
	return (*this += 1);
}
Date Date::operator++ (int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}
Date& Date::operator-- ()
{
	return (*this -= 1);
}
Date Date::operator-- (int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
int Date::operator- (const Date& d)
{
	int count = 0;
	Date Max = *this;
	Date Min = d;
	if (Max > Min)
	{
		while (!(*this == d))
		{
			*this -= 1;
			count++;
		}
	}
	else if (Max < Min)
	{
		while (!(*this == d))
		{
			*this += 1;
			count--;
		}
	}
	return count;
}


ostream* operator<<(ostream* out, const Date &d)
{
	out << d._year << '-' << d._month << '-' << d._day << endl;
	return out;
}

