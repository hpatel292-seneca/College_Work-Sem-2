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

#include<iostream>
#include "Hero.h"
using namespace std;
namespace sdds
{
	void Hero::set_powerLevel()
	{
		int sum = 0;
		for (int i = 0; i < m_num_powers; i++)
		{
			sum += m_power[i].checkRarity();
		}
		m_powerLevel = sum * m_num_powers;
	}

	Hero::Hero()
	{
		m_power = 0;
		m_num_powers = 0;
		m_powerLevel = 0;
		//m_name = '/0';
	}

	Hero::Hero(const char* name, Power powers[], int num_powers)
	{
		U.strcpy(m_name, name);
		m_num_powers = num_powers;
		m_power = new Power[num_powers];
		for (int i = 0; i < num_powers; i++)
		{
			m_power[i] = powers[i];
		}
		set_powerLevel();
	}

	std::ostream& Hero::display(std::ostream& ostr)const
	{
		ostr << "Name: " << m_name << endl;
		ostr << "List of avalible powers:" << endl;
		for (int i = 0; i < m_num_powers; i++)
		{
			ostr <<"  Name: "<< m_power[i].checkName()<<", Rarity: "<<m_power[i].checkRarity() << endl;
		}
		ostr << "Power Level: " << m_powerLevel << endl;
		return ostr;
		// TODO: insert return statement here
	}

	Hero& Hero::operator+=(const Power& right)
	{
		Power* tmp;
		tmp = m_power;
		m_num_powers++;
		m_power = new Power[m_num_powers];
		for (int i = 0; i < m_num_powers-1; i++)
		{
			m_power[i] = tmp[i];
		}
		m_power[m_num_powers - 1] = right;
		delete[] tmp;
		set_powerLevel();
		return *this;
	}

	Hero& Hero::operator-=(const int& right)
	{
		m_powerLevel -= right;
		return *this;
	}

	int Hero::checkPowerLevel() const
	{
		return m_powerLevel;
	}

	Hero::~Hero()
	{
		delete[] m_power;
	}

	
	
	

	std::ostream& operator<<(std::ostream& ostr, const Hero& right)
	{
		right.display(ostr);
		return ostr;
	}

	bool operator<(const Hero& left, const Hero& right)
	{
		return right.checkPowerLevel() > left.checkPowerLevel();
	}

	bool operator>(const Hero& left, const Hero& right)
	{
		return right.checkPowerLevel() < left.checkPowerLevel();
	}

	Hero& operator>>(const Power& left, Hero& right)
	{
		right += left;
		return right;
	}

	Hero& operator<<(Hero& left, const Power& right)
	{
		left += right;
		return left;
	}

}