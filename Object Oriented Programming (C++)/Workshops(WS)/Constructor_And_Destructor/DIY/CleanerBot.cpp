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

#include<iostream>
#include "CleanerBot.h"
#include"Utils.h"
using namespace std;
namespace sdds
{
	CleanerBot::CleanerBot()
	{
		set();
	}
	CleanerBot::CleanerBot(const char* location, double battery, int brushes, bool active)
	{
		set(location, battery, brushes, active);
	}
	CleanerBot::~CleanerBot()
	{
		deallocate();
	}
	void CleanerBot::set()
	{
		m_location = nullptr;
		m_battery = 0.0;
		m_no_brushes = 0;
		m_active = false;
	}
	void CleanerBot::set(const char* location, double battery, int brushes, bool active)
	{
		if (location != nullptr && battery >= 0.0 && brushes >= 0)
		{
			m_location = U.aloCopy(location);
			m_battery = battery;
			m_active = active;
			m_no_brushes = brushes;
		}
	}
	void CleanerBot::setLocation(char* location)
	{
		deallocate();
		if (location != nullptr)
		{
			m_location = U.aloCopy(location);
		}
	}
	void CleanerBot::setActive(bool active)
	{
		m_active = active;
	}
	void CleanerBot::deallocate()
	{
		delete m_location;
		m_location = nullptr;
	}
	char* CleanerBot::getlocation() const
	{
		return m_location;
	}
	double CleanerBot::getBattery() const
	{
		return m_battery;
	}
	int CleanerBot::getBrush() const
	{
		return m_no_brushes;
	}
	bool CleanerBot::isActive() const
	{
		return m_active;
	}
	bool CleanerBot::isValid() const
	{
		bool ret = false;
		if (m_location != nullptr && m_battery >0.0 && m_no_brushes > 0)
		{
			ret = true;
		}
		return ret;
	}
	void CleanerBot::display() const
	{
		if (isValid())
		{
			cout.setf(ios::left);
			cout<<"| ";
			cout.width(10);
			cout << m_location << " | "; 
			cout.unsetf(ios::left);
			cout.width(7);
			cout.setf(ios::fixed);
			cout.precision(1);
			cout << m_battery << " | ";
			cout.width(18);
			cout << m_no_brushes << " | ";
			cout.width(6);
			cout.setf(ios::left);
			cout << m_active ? "YES" : "NO";
			cout << " |"<<endl;
			cout.unsetf(ios::left);
		}
		
	}
	
	int report(CleanerBot* bot, short num_bots)
	{
		int invalid = 0;
		printReportHeader();
		for (int i = 0; i < num_bots; i++)
		{
			if (bot[i].isValid())
			{
				bot[i].display();
			}
			else { invalid++; }
		}
		cout <<endl<< "|====================================================|" << endl <<
			"| LOW BATTERY WARNING :                              |" << endl <<
			"|====================================================| " << endl;
		cout << "| Number of robots to be charged: " << invalid << "                  |" << endl;
		cout << "| Sorting robots based on their available power:     |" << endl;
		cout<<  "| Location   | Battery |  Number of Brushes | Active |" << endl <<
			    "|------------+---------+--------------------+--------|" << endl;
		sort(bot, num_bots);
		for (int i = 0; i < num_bots; i++)
		{
			if (bot[i].isValid())
			{
				bot[i].display();
			}
		}
		return 0;
	}
	void sort(CleanerBot* bot, short num_bots)
	{
		CleanerBot tmp;
		for (int i = num_bots - 1; i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (bot[j].getBattery() < bot[j + 1].getBattery())
				{
					tmp = bot[j];
					bot[j] = bot[j + 1];
					bot[j + 1] = tmp;
					tmp.set();
				}
			}
		}
	}
	void printReportHeader()
	{
		cout << "         ------ Cleaner Bots Report -----" << endl;
		cout << "     ---------------------------------------" << endl <<
			"| Location   | Battery |  Number of Brushes | Active |" << endl <<
			"|------------+---------+--------------------+--------|" << endl;
	}
}

