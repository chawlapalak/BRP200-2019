/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK9- At home
31 March 2019*/

#ifndef SICT_DATA_H
#define SICT_DATA_H
#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;

namespace sict {

	const int COLUMN_WIDTH    = 15;
	const int smallestnum = 0;
	const int largestnum = 1000000000;
	const int recordDes_width = 20;

	template <typename T>
	T max(const T* data, int n)
	{
		int maximum = smallestnum;
		for(int i = 0; i < n; i++)
		{
			if (data[i] >= maximum)
			{
				maximum = data[i];
			}
		}
		return maximum;

	}

	template <typename T>
	T min(const T* data, int n)
	{
		int minimum = largestnum;
		for (int i = 0; i < n; i++)
		{
			if (data[i] <= minimum)
			{
				minimum = data[i];
			}
		}
		return minimum;
	}

	template <typename T>
	T sum(const T* data, int n) {
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += data[i];
		}
		return sum;
	}
	

	
	template <typename T>
	double average(const T* data, int n) {
		T avg = sum(data, n) / n;
		return avg;
	}

	template <typename T>
	bool read(std::istream& input, T* data, int n) {
		for (int i = 0; i < n; i++)
		{
			T value;
			input.ignore();
			input >> value;
			if (input.fail())
			{
				return false;
			}
			else
			{
				data[i] = value;
			}
		}
		return true;
	}
	

	template <typename T>
	void display(const char* name, const T* data, int n) {
		cout.width(20);
		cout << name;
		for (int i = 0; i < n; i++)
		{
			cout.width(COLUMN_WIDTH);
			cout << data[i];
		}
		cout << endl;

	}

	
	template <typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n)	{
		char rowname[2000];
		bool ok = !input.bad();
		if (ok) {
			input.get(rowname, 2000, ',');
			 
			if (strcmp(rowname, name) != 0) 
			{
				cout << "Cannot parse row for " << name << endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			ok = read(input, data, n);

		input.ignore(2000, '\n');
		return ok;
	}

	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
	
}

#endif