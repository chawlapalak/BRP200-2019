/*Name : Palak Chawla
Section : SCC
ID : 118834175
MS1
email : pchawla5@myseneca.ca
10 March 2019*/

#include<iostream>
#include<iomanip>
#include "Date.h"

using namespace std;

namespace ama
{

	void ama::Date::safeEmpty()
	{
		Day = 00;
		Month = 00;
		Year = 0000;
		status(no_error); //safe-empty
	}

	Date::Date()
	{
		safeEmpty();
	}

	Date::Date(int yr, int month, int day)
	{
		if (yr < min_year || yr > max_year) {
			safeEmpty();
			status(error_year);
		}
		else if (month < 1 || month > 12) {
			safeEmpty();
			status(error_mon);
		}
		else if (day < 1 || day > mdays(yr, month)) {
			safeEmpty(); 
			status(error_day);
		}
		
		else
		{
			Year = yr;
			Month = month;
			Day = day;
			status(no_error);
			
		}
	}

	int Date::status() const
	{
		return Status;
	}

	void Date::clearError()
	{
		if (Status != 0)
		{
			status(no_error);
		}
}

bool Date::isGood() const
{
	if (Status!= no_error || ( Year < min_year && Month < 1 && Day <1))
	{
		return false;
	}
	return true;
}

Date& Date::operator+=(int days)
{
	if (isGood() && days > 0) {
		int tempDays = this->Day + days;
		if (tempDays > mdays(Year, Month)) {
			status(error_invalid_operation);
		}
		else {
			Day = tempDays;
		}
	}
	else {
		status(error_invalid_operation);
	}

	return *this;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int days)
{
	Date temp = *this;
	++*this;
	return temp;
}

Date Date::operator+(int days)
{
	Date temp = *this;
	temp += days;
	return temp;
}

bool Date::operator==(const Date & rhs) const
{

	if (this->Day == rhs.Day && this->Month == rhs.Month && this->Year == rhs.Year)
	{
		return true;
	}
	return false;
}

bool Date::operator!=(const Date & rhs) const
{
	if (*this == rhs)
		return false;
	return true;
}

bool Date::operator<(const Date & rhs) const
{
	if (this->Year < rhs.Year || this->Month < rhs.Month || this->Day < rhs.Day )
	{
		return true;
	}
	return false;
}

bool Date::operator>(const Date & rhs) const
{
	if (this->Year > rhs.Year || this->Month > rhs.Month || this->Day > rhs.Day)
	{
		return true;
	}
	return false;
}

bool Date::operator<=(const Date & rhs) const
{
	if (*this== rhs || *this < rhs)
	{
		return true;
	}
	return false;
}

bool Date::operator>=(const Date & rhs) const
{
	if (*this == rhs || *this > rhs)
	{
		return true;
	}
	return false;
}

void Date::status(int newStatus)
{
	Status = newStatus;
}

int Date::mdays(int year, int mon) const
{
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
	int month = mon >= 1 && mon <= 12 ? mon : 13;
	month--;
	return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));

}

std::istream & Date::read(std::istream & istr)
{	
	char delimeter;
	istr.clear();
	clearError();
	istr >> Year >> delimeter >> Month >> delimeter >> Day;

	if (istr.fail())
	{
		*this = Date();
		status(error_input);
	}
	else if (Year < min_year || Year > max_year) {
		safeEmpty();
		status(error_year);
	}
	else if (Month < 1 || Month > 12) {
		safeEmpty();
		status(error_mon);
	}
	else if (Day < 1 || Day > mdays(Year, Month)) {
		safeEmpty();
		status(error_day);
	}

	return istr;
}

std::ostream & Date::write(std::ostream & ostr) const
{
	
	if (Year == 0) {
		ostr << "000" << Year << "/";
	}
	else
	{
		ostr << Year << "/";
	}
	if (Month >= 0 && Month < 10) {
		ostr << "0"<< Month <<"/";
	}
	else
	{
		ostr << Month <<"/";
	}


	if (Day >= 0 && Day < 10) {
		ostr << "0" << Day;
	}
	else {
		ostr << Day;
	}

	
	return ostr;
}

std::istream & operator>>(std::istream & is, Date & D)
{
	return D.read(is);
}

std::ostream & operator<<(std::ostream & ostr, const Date & D)
{
	return D.write(ostr);
}

}



