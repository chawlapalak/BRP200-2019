/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK8- In lab
20 March 2019*/

#include<iomanip>
#include "SavingsAccount.h"

using namespace std;

namespace sict {

	void sict::SavingsAccount::safeEmpty()
	{
		interest = 0.0;
		//safe-empty space
	}


	sict::SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance)
	{
		if (interestRate > 0.0) 
		{
			interest = interestRate;
		}
		else{
		safeEmpty();
		}
	}

	void sict::SavingsAccount::monthEnd()
	{
		double interestEarned = Account::balance() * interest;
		credit(interestEarned);
	}

	void sict::SavingsAccount::display(std::ostream & out) const
	{
		out << "Account type: Savings" << endl;
		out << std::fixed << "Balance: $" << std::setprecision(2) << balance() << endl;
		out << std::fixed << "Interest Rate (%): "<< std::setprecision(2) << interest * 100 << endl;

	}
}