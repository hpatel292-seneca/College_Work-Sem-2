/*
*****************************************************************************
						  Workshop - #3 (W4P2)
Full Name  : Harshil patel
Student ID#: 148847213
Email      : hpatel292@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/

#ifndef SDDS_CLEANERBOT_H
#define SDDS_CLEANERBOT_H
namespace sdds
{
	class CleanerBot
	{
		char* m_location{};
		double m_battery{};
		int m_no_brushes{};
		bool m_active{};
	public:
		CleanerBot();
		CleanerBot(const char* location, double battery, int brushes, bool active);
		~CleanerBot();
		void set();
		void set(const char* location, double battery, int brushes, bool active);
		void setLocation(char* location);
		void setActive(bool active);
		void deallocate();
		char* getlocation()const;
		double getBattery()const;
		int getBrush()const;
		bool isActive()const;
		bool isValid()const;
		void display()const;
	};
	int report(CleanerBot* bot, short num_bots);
	void sort(CleanerBot* bot, short num_bots);
	void printReportHeader();
}
#endif // !SDDS_CLEANERBOT_H

