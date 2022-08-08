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
#include"Publication.h"
#define SDDS_FILE_SIZE 256
namespace sdds
{
	class LibApp
	{
		//changes for ms5
		char m_filename[SDDS_FILE_SIZE];
		Publication* m_PPA[SDDS_LIBRARY_CAPACITY]{};
		int m_NOLP{};
		int m_LLRN{};
		Menu m_title;
		// completes changes for ms5
		bool m_changed{}; 
		Menu m_mainMenu;
		Menu m_exitMenu;
	public:
		bool confirm(const char* message);
		void load();
		void save();
		void read(std::ostream& ostr);
		// mode:-
		// mode = 0  for searching all
		// mode = 1 for searching publication which are on loan
		// mode = 2 for searching avaliable publication
		int search(int mode);
		void returnPub();
		void newPublication();
		void removePublication();
		void checkOutPub();
	
		LibApp(const char* filename);
		void run();
		Publication* getPub(int libRef);
		~LibApp();
	};
}
#endif // !SDDS_LIBAPP_H
