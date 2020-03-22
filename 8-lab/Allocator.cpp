/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK8- In lab
20 March 2019*/

#include"SavingsAccount.h"
using namespace std;

namespace sict
{
	
	iAccount* CreateAccount(const char* type, double balance)
	{
		const double IR = 0.05;
		iAccount * iaccnt = nullptr;
		if (type[0] == 'S')
		{
			iaccnt = new SavingsAccount(balance, IR);
		}
		return iaccnt;
	}
}