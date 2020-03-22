/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK4- At home
email : pchawla5@myseneca.ca
10 February 2019*/


#ifndef SICT_TRAVELER_H
#define SICT_TRAVELER_H

namespace sict 
{
	const int max_destination_size = 32;
	const int max_name_size = 16;
	class Traveler
	{
	public:
		Traveler();
		Traveler(const char* fName, const char* lName, const char* destName);
		Traveler(const char* fName,const char* lName,const char* destName,const int dYear, const int dMonth, const int dDay);
		void display() const;
		bool isEmpty() const;
		const char* name() const;
		bool canTravelWith(const Traveler& coPassenger) const;

	private:
		void safeEmpty();
		char firstName[max_name_size];
		char lastName[max_name_size];
		char Destination[max_destination_size];
		int year;
		int month;
		int day;
	};

	
}

#endif
