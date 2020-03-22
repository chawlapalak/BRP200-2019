/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK6- In lab
email : pchawla5@myseneca.ca
6 March 2019*/


#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H


namespace sict {
	const int max_name_size = 16;
    class Contact
    {
        private:
            char name [max_name_size];
            long long* phoneNumber;
	int len;

        public:
            Contact();
            Contact(const char*, const long long*, int);
            ~Contact();
            bool isEmpty() const;
            void display() const;
    };
}





















#endif