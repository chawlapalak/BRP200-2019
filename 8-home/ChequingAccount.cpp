/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK8- At home
23 March 2019*/
#include<iomanip>
#include"ChequingAccount.h"

using namespace std;

namespace sict
{
	void ChequingAccount::safeEmpty()
	{
		transactionFee = 0.0;
		monthEndFee = 0.0;
		//safe-empty 
	}
	ChequingAccount::ChequingAccount(double balance, double transFee, double monthlyFee) : Account(balance)
	{
		if (transFee > 0) 
		{
			transactionFee = transFee;
		}
		else
		{
			transactionFee = 0.0;
		}
		if (monthlyFee > 0)
		{
			monthEndFee = monthlyFee;
		}
		else
		{
			monthlyFee = 0.0;
		}
	}
	bool ChequingAccount::credit(double amount)
	{
		bool status = false;
		status = Account::credit(amount);
		Account::debit(transactionFee);
		return status;
		
	}
	bool ChequingAccount::debit(double amount)
	{
			bool status = false;
			status = Account::debit(amount);
			Account::debit(transactionFee);
			return status;
	}
	void ChequingAccount::monthEnd()
	{
		Account::debit(monthEndFee);
	}
	void ChequingAccount::display(std::ostream & out) const
	{
		out << "Account type: Chequing" << endl;
		out << std::fixed << "Balance: $" << std::setprecision(2) << balance() << endl;
		out << std::fixed << "Per Transaction Fee: " << std::setprecision(2) << transactionFee << endl;
		out << std::fixed << "Monthly Fee: " << std::setprecision(2) << monthEndFee << endl;
	}
}