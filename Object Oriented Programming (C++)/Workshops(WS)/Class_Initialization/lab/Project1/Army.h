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
#ifndef SDDS_ARMY_H_
#define SDDS_ARMY_H_

namespace sdds
{
	const int MAX_NAME_LEN = 50;
	class Army
	{
		int m_no_units;
		char m_nationality[50];
		double m_power;
	public:
		void setEmpty();
		void createArmy(const char* country, double pow, int troops);
		void updateUnits(int troops);
		const char* checkNationality() const;
		int checkCapacity() const;
		double checkPower() const;
		bool isEmpty() const;
		bool isStrongerThan(const Army& army) const;
	};
	void battle(Army& arm1, Army& arm2);
	void displayDetails(const Army* armies, int size);
}
#endif
