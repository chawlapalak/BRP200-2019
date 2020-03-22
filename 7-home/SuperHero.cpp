/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK7- At home
email : pchawla5@myseneca.ca
14 March 2019*/
#include<iostream>
#include"Hero.h"
#include "SuperHero.h"

using namespace std;

namespace sict {

	void SuperHero::safe_empty()
	{
		SuperHero_strength = 0;
		super_attackBonus = 0;
		//safe-empty bonus
	}

	SuperHero::SuperHero() : Hero()
	{
		safeEmpty();
	}

	SuperHero::SuperHero(const char * SH_name, int SH_health, int SH_attack, int SH_attackBonus, int SH_strength) : Hero(SH_name, SH_health, SH_attack)
	{
		if (SH_attackBonus > 0 && SH_strength > 0)
		{
			super_attackBonus = SH_attackBonus;
			SuperHero_strength = SH_strength;
		}

	}

	int SuperHero::attackStrength() const
	{
		if (Hero::attackStrength() == 0)
		{
			return 0;
		}
		return  Hero::attackStrength() + super_attackBonus;

	}

	int SuperHero::defend() const
	{
		if (SuperHero_strength == 0)
		{
			return 0;
		}
		return SuperHero_strength;
	}

	const SuperHero & operator*(const SuperHero & first, const SuperHero & second)
	{
		SuperHero one = first;
		SuperHero two = second;
		int rounds = 0;
		const SuperHero * winner = nullptr;
		
		int Damageone = two.attackStrength() - one.defend();
		int Damagetwo = one.attackStrength() - two.defend();
		
		while (one.isAlive() && two.isAlive() && rounds < max_rounds)
		{
			one -= Damageone;
			two -= Damagetwo;
			rounds++;
		}
		if (one.isAlive() && two.isAlive())
		{
			winner = &first;
		}
		else if (one.isAlive())
		{
			winner = &first;
		}
		else
		{
			winner = &second;
		}

		cout << "Super Fight! " << first << " vs " << second << " : Winner is " << *winner << " in " << rounds << " rounds." << endl;
		return *winner;

	}
}