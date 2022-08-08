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

#include<iostream>
#include<fstream>
#include"LibApp.h"
#include"Book.h"
#include"Utils.h"
#include"PublicationSelector.h"

//constants for the search 
#define ALL 0
#define LOAN 1
#define AVALIBLE 2
using namespace std;
namespace sdds
{
	bool LibApp::confirm(const char* message)
	{
		bool ret{};
		Menu menu(message);
		menu << "Yes";
		int selection = menu.run();
		if (selection == 1)
		{
			ret = true;
		}
		return ret;
	}
	void LibApp::load()
	{
		char type{};
		cout << "Loading Data" << endl;
		ifstream infile(m_filename);
		/*if (infile.is_open())
		{
			infile >> type;
			if (type == 'P')
			{
				m_PPA[m_NOLP] = new Publication;
				m_PPA[m_NOLP]->read(infile);
			}
			else if (type == 'B')
			{
				m_PPA[m_NOLP] = new Book;
				m_PPA[m_NOLP]->read(infile);
			}
		}*/
		while (!infile.fail()) {
			infile >> type;
			if (infile) {
				if (type == 'P')
					m_PPA[m_NOLP] = new Publication;
				else if (type == 'B')
					m_PPA[m_NOLP] = new Book;
				if (m_PPA[m_NOLP]) {
					infile >> *m_PPA[m_NOLP];
					m_NOLP++;
				}
			}
		}
		m_LLRN = m_PPA[m_NOLP - 1]->getRef();
		infile.close();
	}
	void LibApp::save()
	{
		cout << "Saving Data" << endl;
		ofstream ostr(m_filename);
		if (ostr)
		{
			for (int i = 0; i < m_NOLP; i++)
			{

				if (m_PPA[i]->getRef() != 0)
				{

					m_PPA[i]->write(ostr);
					ostr << '\n';
				}

			}
		}
		ostr.close();
	}
	void LibApp::read(ostream& ostr)
	{
	}
	int LibApp::search(int mode)
	{
		int ret = 0;
		bool matchFound = false;
		char title[MAX_TITLE];
		/*cout << "Searching for the publication" << endl;*/
		PublicationSelector ps("Select one of the following found matches:");
		int type = m_title.run();
		char typeInChar;
		if (type == 0)
		{
			cout << "Aborted!" << endl;
		}
		else {
			if (type == 1)
			{
				typeInChar = 'B';
			}
			else if (type == 2) {
				typeInChar = 'P';
			}
			cout << "Publication Title: ";
			cin.getline(title, MAX_TITLE + 1);
			if (mode == 0)
			{
				for (int i = 0; i < m_NOLP; i++)
				{
					if (m_PPA[i]->getRef() != 0 && m_PPA[i]->type() == typeInChar)
					{
						if (U.strstr((const char*)(* m_PPA[i]), title) != nullptr) {
							matchFound = true;
							ps << m_PPA[i];
						}
					}
				}
			}
			else if (mode == 1)
			{
				for (int i = 0; i < m_NOLP; i++)
				{
					if (m_PPA[i]->getRef() != 0 && m_PPA[i]->onLoan() == true && m_PPA[i]->type() == typeInChar)
					{
						if (U.strstr((const char*)(* m_PPA[i]), title)) {
							matchFound = true;
							ps << m_PPA[i];
						}
					}
				}
			}
			else if (mode == 2)
			{
				for (int i = 0; i < m_NOLP; i++)
				{
					if (m_PPA[i]->getRef() != 0 && m_PPA[i]->onLoan() == false && m_PPA[i]->type() == typeInChar)
					{
						if (U.strstr((const char*)(* m_PPA[i]), title) != nullptr) {
							matchFound = true;
							ps << m_PPA[i];
						}
					}
				}
			}
			if (matchFound)
			{
				int selection;
				ps.sort();
				selection = ps.run();
				/*cout << "> X (to Exit)" << endl;
				cout << "Row Number(select publication)" << endl;
				cout << "> ";
				U.getIntInRange((int)ps + 1, 0);*/
				if (selection == 0)
				{
					cout << "Aborted!" << endl;
				}
				else {
					ret = selection;
					Publication* pub = getPub(selection);
					cout << *pub << endl;
				}
			}
			else {
				cout << "No matches found!" << endl;
			}
		}

		return ret;
	}
	void LibApp::returnPub()
	{
		cout << "Return publication to the library" << endl;
		int ref = search(LOAN);
		Publication* pub = getPub(ref);
		if (ref != 0)
		{
			if (confirm("Return Publication?") == 1)
			{
				double penalty{};
				Date checkoutDate = pub->checkoutDate();
				Date today;
				today.setToToday();
				int DaysOnLoan = today.daysSince0001_1_1() - checkoutDate.daysSince0001_1_1();
				if (DaysOnLoan > 15)
				{
					penalty = (DaysOnLoan - 15) * 0.5;
					cout << "Please pay $";
					cout.setf(ios::fixed);
					cout.precision(2);
					cout << penalty;
					cout << " penalty for being " << (DaysOnLoan - 15) << " days late!" << endl;
				}
				pub->set(0);
				m_changed = true;
				cout << "Publication returned" << endl;
			}
		}
	}
	void LibApp::newPublication()
	{
		if (m_NOLP == SDDS_LIBRARY_CAPACITY)
		{
			cout << "Library is at its maximum capacity!" << endl;
		}
		else {
			Publication* ptr{};
			cout << "Adding new publication to the library" << endl;
			int type = m_title.run();
			if (type == 0)
			{
				cout << "Aborted!" << endl;
			}
			else {
				if (type == 1)
				{
					ptr = new Book;
				}
				else if (type == 2)
				{
					ptr = new Publication;
				}
				if (ptr)
				{
					(*ptr).read(cin);
					if (cin.fail())
					{
						cin.ignore(10000, '\n');
						cout << "Aborted!" << endl;
					}
					else {
						if (confirm("Add this publication to the library?") == 1) {
							if (*ptr)
							{
								m_LLRN++;
								ptr->setRef(m_LLRN);
								m_PPA[m_NOLP] = ptr;
								m_NOLP++;
								m_changed = true;
								cout << "Publication added" << endl;
							}
							else {
								cout << "Failed to add publication" << endl;
							}
						}
						else {
							cout << "Aborted!" << endl;
						}
					}
				}
			}
		}
	}
	void LibApp::removePublication()
	{
		cout<<"Removing publication from library"<<endl;
		int ref = search(ALL);
		if (ref != 0)
		{
			if (confirm("Remove this publication from the library?") == 1)
			{
				Publication* pub = getPub(ref);
				//pub->setRef(0);
				pub->setRef(0);
				m_changed = true;
				cout << "Publication removed" << endl;
			}
		}
	}
	void LibApp::checkOutPub()
	{
		Publication* pub{};
		int membershipNum{};
		cout << "Checkout publication from the library" << endl;
		int ref = search(AVALIBLE);
		if (true)
		{

		}
		pub = getPub(ref);
		if (confirm("Check out publication?") == 1) {
			cout << "Enter Membership number: ";
			do
			{
				cin >> membershipNum;
				cin.ignore(100, '\n');
				if (membershipNum > 99999 || membershipNum < 10000)
				{
					cout << "Invalid membership number, try again: ";
				}
			} while (membershipNum > 99999 || membershipNum < 10000);
			pub->set(membershipNum);
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
	}
	LibApp::LibApp(const char* filename)
	{
		U.strcpy(m_filename, filename);
		// m_changed = false; reduntant as i initialize it when creating to false.
		m_title.setTitle("Choose the type of publication:");
		m_title << "Book" << "Publication";
		m_mainMenu.setTitle("Seneca Library Application");
		m_exitMenu.setTitle("Changes have been made to the data, what would you like to do?");
		m_mainMenu << "Add New Publication"  
			       << "Remove Publication" 
			       << "Checkout publication from library" 
			       << "Return publication to library";
		m_exitMenu << "Save changes and exit"
			<< "Cancel and go back to the main menu";
		load();
	}
	void LibApp::run()
	{
		int selection;
		bool exit = true;
		do
		{
			selection = m_mainMenu.run();
			switch (selection)
			{
			case 0:
				if (m_changed) {
					int select = m_exitMenu.run();
					if (select == 1) {
						save();
						exit = false;
					}
					else if (select == 2) {
						cout << endl;
					}
					else if (select == 0) {
						if (confirm("This will discard all the changes are you sure?") == 1)
						{
							exit = false;
						}
					}
				}
				else {
					exit = false;
				}
				if (!m_changed || exit == false)
				{
					cout << endl;
					cout << "-------------------------------------------" << endl <<
						"Thanks for using Seneca Library Application" << endl;
					ifstream istr(m_filename);
					
				}
				break;
			case 1:
				newPublication();
				cout << endl;
				break;
			case 2:
				removePublication();
				cout << endl;
				break;
			case 3:
				checkOutPub();
				cout << endl;
				break;
			case 4:
				returnPub();
				cout << endl;
				break;
			default:
				cout << "you have selected out of the range" << endl;
				break;
			}
		} while (exit);
	}
	Publication* LibApp::getPub(int libRef)
	{
		Publication* ret{};
		for (int i = 0; i < m_NOLP && ret==nullptr; i++)
		{
			if (m_PPA[i]->getRef() == libRef)
			{
				ret = m_PPA[i];
			}
		}
		return ret;
	}
	LibApp::~LibApp()
	{
		for (int i = 0; i < m_NOLP; i++)
		{
			delete m_PPA[i];
		}
	}
}