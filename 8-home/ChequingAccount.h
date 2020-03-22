/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK8- At home
23 March 2019*/
#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H

#include<iostream>
#include"Account.h"

using namespace std;
namespace sict
{
	class ChequingAccount : public Account
	{
	private:
		double transactionFee;
		double monthEndFee;

	public:
		void safeEmpty();
		ChequingAccount(double balance, double transFee,double monthlyFee);
		bool credit(double amount);
		bool debit(double amount);
		void monthEnd();
		void display(std::ostream& out) const;

	};
}

#endif
