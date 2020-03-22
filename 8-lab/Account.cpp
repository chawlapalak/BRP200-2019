/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK8- In lab
20 March 2019*/

#include "Account.h"
using namespace std;

namespace sict {
	void sict::Account::safeEmpty()
	{
		bal = 0.0;
		//safe-empty space
	}
	
	sict::Account::Account(double balance)
	{
		if (balance < 0)
		{
			safeEmpty();
		}
		bal = balance;
	}

	bool sict::Account::credit(double amount)
	{
		if (amount > 0)
		{
			bal += amount;
			return true;
		}
		return false;
	}

	bool sict::Account::debit(double amount)
	{
		if (amount > 0)
		{
			bal -= amount;
			return true;
		}
		return false;
	}

	double sict::Account::balance() const
	{
		return bal;
	}
}