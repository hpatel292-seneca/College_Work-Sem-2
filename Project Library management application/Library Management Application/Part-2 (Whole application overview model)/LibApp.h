/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author	Harshil Patel(148847213)
Revision History
-----------------------------------------------------------
Date: 2022/7/7
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include"Menu.h"
namespace sdds
{
	class LibApp
	{
		bool m_changed{}; // using this as a flag that is off if no changes have and set to true if it has done some changes. the use is that when we are exiting the program then we would ask to confirm the changes.
		// this is giving me error when i am initialize it by ()
		Menu m_mainMenu;
		Menu m_exitMenu;
		bool confirm(const char* message);
		void load();
		void save();
		void search();
		void returnPub();
		void newPublication();
		void removePublication();
		void checkOutPub();
	public:
		LibApp();
		void run();
	};
}
#endif // !SDDS_LIBAPP_H
