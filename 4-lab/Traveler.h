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
		Traveler(const char* fName,const char* lName,const char* destName);
		void display() const;
		bool isEmpty() const;

	private:
		char firstName[max_name_size];
		char lastName[max_name_size];
		char Destination[max_destination_size];
	};

	
}

#endif
