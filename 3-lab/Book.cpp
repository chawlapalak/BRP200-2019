#include<iostream>
#include<cstring>
#include"Book.h"

using namespace std;

namespace sict 
{
	void Book::set(const char * g_name, const char * f_name, const char * m_title,long long m_isbn)
	{
		if (m_isbn <= max_isbn_value && m_isbn >= min_isbn_value)
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

	void Book::display() const
	{
		if (isEmpty())
		{
			cout << "The book object is empty!" << endl;
		}
		else
		{
			cout << "Author: " << family_name << ", " << given_name << endl;
			cout << "Title: " << title << endl;
			cout << "ISBN-13: " << isbn << endl;
		}
	}

}