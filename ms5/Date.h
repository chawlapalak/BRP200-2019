/*Name : Palak Chawla
Section : SCC
ID : 118834175
ms5
email : pchawla5@myseneca.ca
07 April 2019*/

#ifndef AMA_DATE_H
#define AMA_DATE_H
#include<iostream>
namespace ama
{
	const int min_year = 2019;
	const int max_year = 2028;
	const int no_error = 0;
	const int error_year = 1;
	const int error_mon = 2;
	const int error_day = 3;
	const int error_invalid_operation = 4;
	const int error_input = 5;

	class Date
	{		
	public:
		Date();
		Date(int yr,int month, int day);
		int status() const;
		void clearError();
		bool isGood() const;
		Date& operator +=(int days);
		Date& operator ++();
		Date operator ++(int);
		Date operator +(int days);
		bool operator ==(const Date& rhs) const;
		bool operator !=(const Date& rhs) const;
		bool operator <(const Date& rhs) const;
		bool operator >(const Date& rhs) const;
		bool operator <=(const Date& rhs) const;
		bool operator >=(const Date& rhs) const;

		std::istream& read(std::istream& is);
		std::ostream& write(std::ostream& os) const;
	
	private:
		int Year;
		int Month;
		int Day;
		int Status;
		void status(int newStatus);
		int mdays(int year, int month) const;
		void safeEmpty();
	};
	std::istream& operator>>(std::istream& is, Date& D);
	std::ostream& operator<<(std::ostream& ostr, const Date& D);
}
#endif