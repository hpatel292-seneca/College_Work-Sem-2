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
#include"LibApp.h"

using namespace std;
namespace sdds
{
	bool LibApp::confirm(const char* message)
	{
		bool ret{};
		Menu menu(message);
		menu << "yes";
		int selection = menu.run();
		if (selection == 1)
		{
			ret = true;
		}
		return ret;
	}
	void LibApp::load()
	{
		cout << "Loading Data" << endl;
	}
	void LibApp::save()
	{
		cout << "Saving Data" << endl;
	}
	void LibApp::search()
	{
		cout << "Searching for the publication" << endl;
	}
	void LibApp::returnPub()
	{
		search();
		cout << "Returing publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;
	}
	void LibApp::newPublication()
	{
		cout << "Adding new publication to library" << endl;
		if (confirm("Add this publication to library?") == 1) {
			m_changed = true;
			cout << "Publication added" << endl;
		}

	}
	void LibApp::removePublication()
	{
		cout<<"Removing publication from library"<<endl;
		search();
		if (confirm("Remove this publication from the library?") == 1)
		{
			m_changed = true;
			cout << "Publication removed" << endl;
		}
	}
	void LibApp::checkOutPub()
	{
		search();
		if (confirm("Check out publication?") == 1) {
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
	}
	LibApp::LibApp()
	{
		// m_changed = false; reduntant as i initialize it when creating to false.
		m_mainMenu.setTitle("Seneca Libray Application");
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
}