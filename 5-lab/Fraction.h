// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
// TODO: create namespace
namespace sict {

	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int num;
		int denom;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		// TODO: declare public member functions
		void safeEmptySpace();
		Fraction();
		Fraction(int numerator, int denominator);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator + (const Fraction& rhs)const;
	};
}
#endif