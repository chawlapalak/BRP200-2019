/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK7- At home
email : pchawla5@myseneca.ca
13 March 2019*/

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

#include"Hero.h"

namespace sict
{

	class SuperHero : public Hero
	{
	private:
		int super_attackBonus;
		int SuperHero_strength;

	public:
		void safe_empty();
		SuperHero();
		SuperHero(const char* SH_name, int SH_health, int SH_attack, int SH_attackBonus, int SH_strength);
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif