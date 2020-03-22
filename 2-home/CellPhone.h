/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK2- At home
email : pchawla5@myseneca.ca
27 January 2019*/

// TODO: header safeguards
#ifndef SICT_CELLPHONE_H
#define SICT_CELLPHONE_H

// TODO: sict namespace
namespace sict {
	
	// TODO: define the structure CellPhone in the sict namespace
	struct CellPhone{
		char m_model[32];
		float m_price;
	};
// TODO: declare the function display(...),
//         also in the sict namespace
	void display(const CellPhone &cp);
	void display(const CellPhone* cellphones, int size);
}
#endif