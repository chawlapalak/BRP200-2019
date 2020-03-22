/*Name : Palak Chawla
Section : SCC
ID : 118834175
WK7- At home
email : pchawla5@myseneca.ca
14 March 2019*/

#ifndef SICT_HERO_H
#define SICT_HERO_H

namespace sict
{
	const int max_rounds = 100;
	class Hero
	{
	private:
		char name[41];
		int health;
		int attackStren;
	
	public:
		void safeEmpty();
		Hero();
		Hero(const char* hero_name,int hero_health, int hero_attackStr);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};
	const Hero& operator*(const Hero& first, const Hero& second);
}
#endif
