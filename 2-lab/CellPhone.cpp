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
}