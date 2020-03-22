/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK8- At home
23 March 2019*/

#include"SavingsAccount.h"
#include"ChequingAccount.h"
using namespace std;

namespace sict
{
	
	iAccount* CreateAccount(const char* type, double balance)
	{
		const double IR = 0.05;
		const double TF = 0.50;
		const double MF = 2.00;

		iAccount * iaccnt = nullptr;
		if (type[0] == 'S')
		{
			iaccnt = new SavingsAccount(balance, IR);
			return iaccnt;
		}
		else if (type[0] == 'C')
		{
			iaccnt = new ChequingAccount(balance, TF, MF);
			return iaccnt;
		}
		else
			return nullptr;
		
	}
}