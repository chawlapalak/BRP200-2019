/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK3- At home
email : pchawla5@myseneca.ca
3 February 2019*/

#include<iostream>
#include<cstring>
#include<iomanip>
#include"Book.h"

using namespace std;

namespace sict
{
	void Book::set(const char * g_name, const char * f_name, const char * m_title, long long m_isbn)
	{
			if (isISBNValid(m_isbn))
			{
				strncpy(family_name, f_name, max_name_size + 1);
				family_name[max_name_size] = '\0';
				strncpy(given_name, g_name, max_name_size + 1);
				given_name[max_name_size] = '\0';
				strncpy(title, m_title, max_title_size + 1);
				title[max_title_size] = '\0';
				isbn = m_isbn;
			}
			else
			{
				given_name[0] = 0;
				family_name[0] = 0;
				title[0] = 0;
				isbn = 0;
			}
	}

		bool Book::isEmpty() const
		{
			if (isbn <= max_isbn_value && isbn >= min_isbn_value)
			{
				return false;
			}

			else
			{
				return true;
			}
		}

		void Book::set(int year, double price)
		{
			if (!isEmpty())
			{
				pubYear = year;
				bookPrice = price;
			}
		}
		void Book::display(bool multiLine) const
		{
			if (isEmpty() && multiLine == false)
			{
				cout << "The book object is empty!" << endl;
			}
			else if (!isEmpty() && multiLine == false)
			{
				cout << "Author: " << family_name << ", " << given_name << endl;
				cout << "Title: " << title << endl;
				cout << "ISBN-13: " << isbn << endl;
				cout << "Publication Year: " << pubYear << endl;
				cout << "Price: " << bookPrice << endl;
			}
			else if (isEmpty() && multiLine == true)
			{
				cout << "|";
				cout.width(92);
				cout << left;
				cout << "The book object is empty!" << "|" << endl;
			}
			else
			{
				cout << "|";
				cout.width(max_name_size);
				cout << right;
				cout << family_name << "|";
				cout.width(max_name_size);
				cout << right;
				cout <<	given_name << "|";
				cout.width(max_title_size);
				cout << left;
				cout << title << "|";
				cout << right;
				cout.width(13);
				cout << isbn << "|";
				cout << right;
				cout.width(4);
				cout << pubYear << "|";
				cout << right;
				cout.width(6);
				cout << fixed <<  setprecision(2)<< bookPrice << "|" << endl;
			}
		}

		bool Book::isISBNValid(long long m_isbn) const
		{
			if (m_isbn <= max_isbn_value && m_isbn >= min_isbn_value)
			{
				int totalSum = 0;
				int totalSumEven = 0;
				int totalSumOdd = 0;
				int checkDigit = m_isbn % 10;
				long long temp_isbn = m_isbn / 10;
				while (temp_isbn != 0)
				{
					int a = temp_isbn % 10;
					totalSumEven = totalSumEven + a;
					int b = (temp_isbn / 10) % 10;
					totalSumOdd = totalSumOdd + b;
					temp_isbn = temp_isbn / 100;
				}
				totalSum = (totalSumEven * 3) + totalSumOdd;
				if ((10 - (totalSum % 10)) == checkDigit)
				{
					return true;
				}
			}
			return false;
		}

		

	
}