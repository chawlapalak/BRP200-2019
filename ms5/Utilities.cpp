/*Name : Palak Chawla
Section : SCC
ID : 118834175
ms5
email : pchawla5@myseneca.ca
07 April 2019*/

#include"Utilities.h"
#include"iProduct.h"
#include"Product.h"
#include "Perishable.h"
using namespace std;

namespace ama
{
	double & operator+=(double & total, const iProduct & prod)
	{	
		total = total + prod.total_cost();
		return total;
	}
	ostream & operator<<(ostream & out, const iProduct & prod)
	{
		return prod.write(out, 2);
	}
	istream & operator>>(istream & in, iProduct & prod)
	{
		prod.read(in, true);
		return in;
	}
    
    iProduct* createInstance(char tag){
        if(tag == 'N' || tag == 'n'){
            return new Product();
        }
        else if(tag == 'P' || tag == 'p'){
            return new Perishable();
        }
        else{
            return nullptr;
        }
    }
}
