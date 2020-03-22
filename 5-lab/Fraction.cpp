// TODO: insert header files
#include<iostream>
#include"Fraction.h"
// TODO: continue the namespace
using namespace std;

namespace sict 
{
	void Fraction::safeEmptySpace()
	{
		denom = 0;//safe-empty state
	}
	// TODO: implement the default constructor
sict::Fraction::Fraction()
{
	safeEmptySpace();
}
	// TODO: implement the two-argument constructor
sict::Fraction::Fraction(int numerator, int denominator)
{
	if (numerator >= 0 && denominator >= 0)
	{
		num = numerator;
		denom = denominator;
		reduce();
	}
	else
	{
		safeEmptySpace();
	}
		
}

	// TODO: implement the max query
int sict::Fraction::max() const
{
	if (num >= denom)
	{
		return num;
	}
	return denom;

}
    // TODO: implement the min query
int sict::Fraction::min() const
{
	if (num >= denom)
	{
		return denom;
	}
	return num;
}


// gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier
	void sict::Fraction::reduce()
	{
		int reduce = gcd();
		num /= reduce;
		denom /= reduce;
	}
    // TODO: implement the display query
	void sict::Fraction::display() const
	{
		if (denom > 1)
		{
			cout << num << "/" << denom;
		}
		else if (isEmpty())
		{
			cout << "no fraction stored";
		}
		else
		{
			cout << num;
		}
	}
	
    // TODO: implement the isEmpty query
	bool sict::Fraction::isEmpty() const
	{
		if (denom == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}
    // TODO: implement the + operator
	Fraction sict::Fraction::operator+(const Fraction & rhs) const
	{
		Fraction temp;

		if (isEmpty() || rhs.isEmpty())
		{
			temp.denom = 0;
		}

		if (!isEmpty() && !rhs.isEmpty())
		{
			temp.denom = denom * rhs.denom;
			temp.num = (num*rhs.denom) + (rhs.num*denom);
			temp.reduce();
		}
		return temp;
	}
	

	
}