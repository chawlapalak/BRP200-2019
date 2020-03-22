/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK8- At home
23 March 2019*/

#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H
#include<iostream>
#include"Account.h"

using namespace std;
namespace sict
{
	class SavingsAccount : public Account
	{
	private:
		double interest;
	public:
		void safeEmpty();
		
		SavingsAccount(double balance, double interestRate);
		void monthEnd();
		void display(std::ostream& out) const;
	
	};
}

#endif
