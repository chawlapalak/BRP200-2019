/*Name : Palak Chawla
Section : SCC
ID : 118834175
ms4
27 March 2019*/

#include"Utilities.h"
#include"iProduct.h"
#include"Product.h"
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
        else{
            return nullptr;
        }
    }
}
