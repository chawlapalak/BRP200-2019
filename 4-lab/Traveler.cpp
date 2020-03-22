#include<iostream>
#include"Traveler.h"
#include<cstring>

using namespace std;

namespace sict
{

	Traveler::Traveler()
	{
		firstName[0] = '\0';
		lastName[0] = '\0';
		Destination[0] = '\0';
		//safe empty state

	}

	Traveler::Traveler(const char * fName, const char * lName, const char * destName)
	{
		if (fName != nullptr && lName != nullptr && destName != nullptr && fName[0] != 0
			&& lName[0] != 0 && destName[0] != 0)
		{
			strcpy(firstName, fName);
			strcpy(lastName, lName);
			strcpy(Destination, destName);
		}
		else
		{
			firstName[0] = '\0';
			lastName[0] = '\0';
			Destination[0] = '\0';
			//safe empty state
		}

	}

	void Traveler::display() const
	{
		if (isEmpty())
		{
			cout << "--> Not a valid traveler! <--" << endl;
		}
		else
		{
			cout << firstName << " " << lastName << " goes to " << Destination << endl;
		}
	}

	bool Traveler::isEmpty() const
	{
		if (firstName[0] == '\0' && lastName[0] == '\0' && Destination[0] == '\0')
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}

	
	
	

}