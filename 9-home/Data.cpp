/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK9- At home
31 March 2019*/

#include<iostream>
#include"Data.h"

using namespace std;

namespace sict {
	

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"

		int popGrowth = population[n - 1] - population[0];
		cout << "Population change from " << year[0] << " to " << year[n - 1] << " is ";
		cout << fixed;
		cout << setprecision(2) << static_cast<double>(popGrowth) / 1000000 << " million" << endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005

		auto VC_start = violentCrime[0];
		auto VC_end = violentCrime[n - 1];
		const char * trend = nullptr;
		if (VC_start < VC_end)
		{
			trend = "up";
		}
		else
		{
			trend = "down";
		}
		cout << "Violent Crime trend is " << trend << endl;

			   		 

		// Q3 print the GTA number accurate to 0 decimal places
		double GTA;
		GTA = average(grandTheftAuto, n);
		cout << "There are ";
		cout << fixed;
		cout << setprecision(2) << GTA / 1000000 << " million Grand Theft Auto incidents on average a year" << endl;



		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;



	}
}