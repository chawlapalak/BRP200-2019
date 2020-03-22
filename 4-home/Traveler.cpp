/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK4- At home
email : pchawla5@myseneca.ca
10 February 2019*/

#include<iostream>
#include<cstring>
#include"Traveler.h"


using namespace std;

namespace sict
{
	void Traveler::safeEmpty()
	{
		firstName[0] = '\0';
		lastName[0] = '\0';
		Destination[0] = '\0';
		year = 0;
		month = 0;
		day = 0;
		//safe empty state
	}
	Traveler::Traveler()
	{
		safeEmpty();
	}

	Traveler::Traveler(const char * fName, const char * lName, const char * destName)
	{
		if (fName != nullptr && lName != nullptr && destName != nullptr && fName[0] != 0
			&& lName[0] != 0 && destName[0] != 0)
		{
			strcpy(firstName, fName);
			strcpy(lastName, lName);
			strcpy(Destination, destName);
			year = 2019;
			month = 07;
			day = 01;
		}
		else
		{
			safeEmpty();
		}
	}

	Traveler::Traveler(const char * fName, const char * lName, const char * destName, const int dYear, const int dMonth, const int dDay) :Traveler(fName, lName, destName)
	{
		if (fName != nullptr && lName != nullptr && destName != nullptr && fName[0] != 0
			&& lName[0] != 0 && destName[0] != 0 && dYear<= 2022 && dYear >=2019 && dMonth >= 1
			&& dMonth <= 12 && dDay >= 1 && dDay <= 31)
		{
			strcpy(firstName, fName);
			strcpy(lastName, lName);
			strcpy(Destination, destName);
			year = dYear;
			month = dMonth;
			day = dDay;
		}
		else
		{
			safeEmpty();
		}

	}

	void Traveler::display() const
	{
		if (this->isEmpty())
		{
			cout << "--> Not a valid traveler! <--" << endl;
		}
		else
		{
			cout << lastName << ", " << firstName << " goes to " << Destination << " on " << year << "/";
			cout.width(2);
			cout.fill('0');
			cout << month;
			cout << "/";
			cout.width(2);
			cout.fill('0');
			cout << day << endl;
		}
	}

	bool Traveler::isEmpty() const
	{
		if (firstName[0] == '\0' && lastName[0] == '\0' && Destination[0] == '\0')
		{
			return true;
		}
		return false;
		
	}

	const char * Traveler::name() const
	{
		return firstName;
	}

	bool Traveler::canTravelWith(const Traveler & coPassenger) const
	{
		if (strcmp(Destination,coPassenger.Destination) == 0 && year == coPassenger.year && month == coPassenger.month && day == coPassenger.day)
		{
			return true;
		}
		return false;

	}


}