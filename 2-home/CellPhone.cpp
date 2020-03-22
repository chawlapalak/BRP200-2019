/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK2- At home
email : pchawla5@myseneca.ca
27 January 2019*/

// TODO: include the necessary headers
#include<iostream>
#include"CellPhone.h"

// TODO: the sict namespace
using namespace std;
namespace sict {
	// TODO: definition for display(...) 

	void display(const CellPhone &cp)
	{
		cout << "Phone " << cp.m_model << " costs $"
			<< cp.m_price << "!" << endl;	
	
	};
	void display(const CellPhone* cellphones, int size)
	{
		cout << "------------------------------" << endl;
		cout << "Phones available at the mall:" << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << ". ";
			display(cellphones[i]);
		}
		float smallest = cellphones[0].m_price;
		for (int i = 1; i < size; i++)
		{
			if (cellphones[i].m_price < smallest)
			{
				smallest = cellphones[i].m_price;
			}
			
		}
		cout << "------------------------------" << endl;
		cout << "The cheapest phone costs $" << smallest << "." << endl;
		cout << "------------------------------" << endl;
	}
}