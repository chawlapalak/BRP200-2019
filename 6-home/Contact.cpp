/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK6- At home
email : pchawla5@myseneca.ca
9 March 2019*/

#include <cstring>
#include <iostream>
#include "Contact.h"


using namespace std;
namespace sict{
	void Contact::safeEmpty()
	{
		//Safe Empty State 
		name[0] = '\0';
		phoneNumber = nullptr;
		len = 0;
	}
	Contact::Contact()
	{
		safeEmpty();
	}

	Contact::Contact(const char *customerName, const long long *customerPhoneNumbers, int size)
	{
		safeEmpty();

		//validate name
		if (customerName != nullptr && customerName[0] != '\0') {
			strncpy(name, customerName, max_name_size-1);
			name[15] = '\0'; 
		}
        int countryCode;
		int areaCode;
		int mainNumber;
        int validPhoneNumber=0;

		for (int i = 0; i < size; i++) {
			
			if (customerPhoneNumbers[i] > 10000000000 && customerPhoneNumbers[i] < 999999999999) {
				countryCode = (customerPhoneNumbers[i] / 10000000000);
				areaCode = ((customerPhoneNumbers[i] % 10000000000) / 10000000);
				mainNumber = customerPhoneNumbers[i] % 10000000;
				if (countryCode >= 1 && countryCode <= 99 &&
					areaCode >= 100 && areaCode <= 999 &&
					mainNumber >= 1000000 && mainNumber <= 99999999) {
                        if(phoneNumber==nullptr){
                            phoneNumber = new long long [validPhoneNumber+1];
                            phoneNumber[validPhoneNumber++] = customerPhoneNumbers[i];
                        }
                        else{
                            long long* temp = new long long [validPhoneNumber+1];
                            for(int j=0; j<validPhoneNumber; j++){
                                temp[j] = phoneNumber[j];
                            }
                            temp[validPhoneNumber++] = customerPhoneNumbers[i];
                           // delete [] phoneNumber;
                            phoneNumber = temp;
                        }
				}
			}
			
		}
		len = validPhoneNumber;

	}

	Contact::Contact(const Contact & rhs)
	{
		safeEmpty();

		strncpy(name, rhs.name, max_name_size - 1);
		name[15] = '\0';
		//copy name

		len = rhs.len;

		if (rhs.phoneNumber != nullptr && rhs.phoneNumber[0] != '\0')
		{
			phoneNumber = new long long[len];
			for (int i = 0; i < len; i++)
			{
				phoneNumber[i] = rhs.phoneNumber[i];
			}
		}

	}

	Contact & Contact::operator=(const Contact & rhs)
	{
		if (this != &rhs)
		{
			safeEmpty();
			this->~Contact();
			new(this)Contact(rhs);
		}
		return *this;
	}

	Contact & Contact::operator+=(long long phn)
	{
		if (name[0] != '\0' && name != nullptr) {
			int countryCode;
			int areaCode;
			int mainNumber;

			if (phn > 10000000000 && phn < 999999999999) {
				countryCode = (phn / 10000000000);
				areaCode = ((phn % 10000000000) / 10000000);
				mainNumber = phn % 10000000;
				if (countryCode >= 1 && countryCode <= 99 &&
					areaCode >= 100 && areaCode <= 999 &&
					mainNumber >= 1000000 && mainNumber <= 99999999)
				{
					len += 1;
					long long * temp = new long long[len];
					for (int i = 0; i < len - 1; i++)
					{
						temp[i] = phoneNumber[i];
					}

					temp[len - 1] = phn;
					delete[] phoneNumber;
					phoneNumber = nullptr;

					phoneNumber = new long long[len];

					for (int i = 0; i < len; i += 1)
					{
						phoneNumber[i] = temp[i];
					}
					delete[] temp;
					temp = nullptr;
				}

			}
		}
		return *this;
	}

	Contact::~Contact()
	{
		delete[] phoneNumber;
	}

	bool Contact::isEmpty() const
	{
		if (name[0] == '\0' && phoneNumber == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	void Contact::display() const
	{
		int countryCode;
		int areaCode;
		int mainNumber;
		int mainNumberPart1;
		int mainNumberPart2;

		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << name << endl;
			if (phoneNumber != nullptr)
			{
				for (int i = 0; i < len; i++) {
					countryCode = (phoneNumber[i] / 10000000000);
					areaCode = ((phoneNumber[i] % 10000000000) / 10000000);
					mainNumber = (phoneNumber[i] % 10000000);
					mainNumberPart1 = mainNumber / 10000;
					mainNumberPart2 = mainNumber % 10000;
					cout << "(+" << countryCode << ") " << areaCode << " " << mainNumberPart1 << "-";
					cout.fill('0');
					cout.width(4);
					cout << mainNumberPart2 << endl;

				}
			}
		}
	}
}
		
