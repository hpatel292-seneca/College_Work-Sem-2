/*
*****************************************************************************
						  Workshop - #3 (W1P2)
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
#ifndef SDDS_BIRTHDATE_H
#define SDDS_BIRTHDATE_H
namespace sdds
{
	const int Max_date = 11;
	struct Date
	{
		int m_year;
		int m_date;
		int m_month;
	};
	struct Employee
	{
		char* m_name;
		Date m_date;
	};
	bool beginSearch(const char* filename);
	bool readName(char* name);
	bool readDate(Date& date);
	bool readBirthDate(int month);
	void displayBirthdays();
	void sort();
	void deallocate();
	void endSearch();
}
#endif // !SDDS_BIRTHDATE_H
