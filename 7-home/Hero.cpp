/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK7- At home
email : pchawla5@myseneca.ca
13 March 2019*/

#include<iostream>
#include<cstring>
#include "Hero.h"

using namespace std;
namespace sict
{
	void Hero::safeEmpty()
	{
		name[0] = '\0';
		health = 0;
		attackStren = 0;
		//safe-empty state
	}
	Hero::Hero()
	{
		safeEmpty();
	}

	Hero::Hero(const char* hero_name, int hero_health,int hero_attackStr)
	{
		if (hero_name == nullptr || hero_name[0] == 0 || hero_health < 0 || hero_attackStr < 0)
		{
			safeEmpty();
		}
		else
		{
			strncpy(name, hero_name, 41);
			name[40] = '\0';
			attackStren = hero_attackStr;
			health = hero_health;
		}
	}

	void Hero::operator-=(int attack)
	{
		if (attack >= 0)
		{
			health -= attack;
			if (health < 0)
			{
				health = 0;
			}
		}
	}

	bool Hero::isAlive() const
	{
		if (health == 0)
		{
			return false;
		}
		return true;
	}

	int Hero::attackStrength() const
	{
		if (attackStren == 0)
		{
			return 0;
		}
		return attackStren;
	}

	ostream& operator<<(std::ostream & os, const Hero & hero)
	{
		if (hero.name[0] == '\0')
		{
			os << "No hero" << endl;
		}
		else
		{
			os << hero.name;
		}
		return os;
	}

	const Hero& operator*(const Hero & first, const Hero & second)
	{
		Hero one = first;
		Hero two = second;
		int rounds = 0;
		const Hero * winner = nullptr;

		while (one.isAlive() && two.isAlive() && rounds < max_rounds)
		{
			one -= two.attackStrength();
			two -= one.attackStrength();
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

		cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << *winner << " in " << rounds << " rounds." << endl;
		return *winner;
	}
}