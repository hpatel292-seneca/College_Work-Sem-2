/*
*****************************************************************************
						  Workshop - #5 (W5P2)
Full Name  : Harshil patel
Student ID#: 148847213
Email      : hpatel292@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/
#ifndef SDDS_HERO_H
#define SDDS_HERO_H
#include"Power.h"
#include"Utils.h"
namespace sdds
{
	class Hero{
	char m_name[MAX_NAME_LENGTH]{};
	Power* m_power{};
	int m_num_powers{};
	int m_powerLevel{};
	void set_powerLevel();
public:
	Hero();
	Hero(const char* name, Power powers[], int num_powers);
	std::ostream& display(std::ostream& ostr = std::cout)const;
	Hero& operator+=(const Power& right);
	Hero& operator-=(const int& right);
	int checkPowerLevel()const;
	~Hero();
	};
	std::ostream& operator<<(std::ostream& ostr, const Hero& right);
	bool operator<(const Hero& left, const Hero& right);
	bool operator>(const Hero& left, const Hero& right);
	Hero& operator>> (const Power& left, Hero& right);
	Hero& operator<< (Hero& left,const Power& right);
}
#endif // !SDDS_HERO_H
