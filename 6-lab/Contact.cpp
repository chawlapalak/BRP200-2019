/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK6- In lab
email : pchawla5@myseneca.ca
6 March 2019*/

#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;
namespace sict{
	Contact::Contact()
	{
		//Safe Empty State 
		name[0] = '\0';
		phoneNumber = nullptr;
		len = 0;
	}

	Contact::Contact(const char *customerName, const long long *customerPhoneNumbers, int size)
	{
		//Safe Empty State
		name[0] = '\0';
		phoneNumber = nullptr;
		len = 0;

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
					areaCode >= 100 && areaCode < 999 &&
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

	Contact::~Contact()
	{
		delete[] phoneNumber;
	}

	bool Contact::isEmpty() const
	{
		if (name[0] == '\0' && phoneNumber == nullptr){
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
