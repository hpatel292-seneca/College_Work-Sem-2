/*
*****************************************************************************
						  Workshop - #3 (W3P1)
Full Name  : Harshil patel
Student ID#: 148847213
Email      : hpatel292@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Army.h"
#include<cstring>
#include<iostream>
using namespace std;
namespace sdds
{
	void Army::setEmpty()
	{
		//m_nationality = nullptr;
		m_no_units = 0;
	}
	void Army::createArmy(const char* country, double pow, int troops)
	{
		if (country != nullptr && strlen(country) > 0 && troops > 0 && pow > 0) {
			strncpy(m_nationality, country, MAX_NAME_LEN);
			m_no_units = troops;
			m_power = pow;
		}
		else {
			setEmpty();
		}
	}
	void Army::updateUnits(int troops)
	{
		m_no_units += troops;
		m_power += troops*0.25;
	}
	const char* Army::checkNationality() const
	{
		return m_nationality;
	}
	int Army::checkCapacity() const
	{
		return m_no_units;
	}
	double Army::checkPower() const
	{
		return m_power;
	}
	bool Army::isEmpty() const
	{
		bool return_value = false;
		if (m_no_units == 0 || m_nationality == 0)
		{
			return_value = true;
		}
		return return_value;
	}
	bool Army::isStrongerThan(const Army& army) const
	{
		return m_power > army.m_power ? true : false;
	}
	void battle(Army& arm1, Army& arm2)
	{
		if (arm1.checkNationality() != nullptr &&      arm2.checkNationality() != nullptr &&
			arm1.checkCapacity() != 0 && arm2.checkCapacity() != 0)
		{
			if (arm1.isStrongerThan(arm2)) {
				cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", " << arm1.checkNationality() << " is victorious!" << endl;
				arm2.updateUnits(-arm2.checkCapacity()/2);
			}
			else if (arm2.isStrongerThan(arm1)) {
				cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", " << arm2.checkNationality() << " is victorious!" << endl;
				arm1.updateUnits(-arm1.checkCapacity() / 2);
			}
		}
	}
	void displayDetails(const Army* armies, int size) {
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << "Armies reporting to battle:" << endl;
		if (armies != nullptr)
		{
			for (int i = 0; i < size; i++)
			{
				if (armies[i].checkCapacity() != 0)
				{
					cout << "Nationality: " << armies[i].checkNationality() << ", Units Count: " << armies[i].checkCapacity() << ", Power left: " << armies[i].checkPower() << endl;
				}
			}
		}
	}
}
