/*Name : Palak Chawla
Section : SCC
ID : 118834175
ms4
27 March 2019*/

#ifndef AMA_UTILITIES_H
#define AMA_UTILITIES_H
#include "iProduct.h"
using namespace std;
namespace ama
{
	double& operator+=(double& total, const iProduct& prod);
	ostream& operator<<(ostream& out, const iProduct& prod); 
	istream& operator>>(istream& in, iProduct& prod); 
    iProduct* createInstance(char tag);
}
#endif

