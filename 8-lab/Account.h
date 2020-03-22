/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK8- In lab
20 March 2019*/

#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H
#include"iAccount.h"
namespace sict
{
	class Account : public iAccount
	{
	private :
		double bal;
	public:
		void safeEmpty();
		Account(double balance);
		bool credit(double amount);
		bool debit(double amount);
	protected:
		double balance() const;
	};
}

#endif
