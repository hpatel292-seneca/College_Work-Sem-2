/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
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
#include"Menu.h"
#include"Utils.h"
using namespace std;
namespace sdds
{
	Menuitem::Menuitem(const char* name) {
		set(name);
	}
	Menuitem::Menuitem() {
		m_name = nullptr;
	}
	Menuitem::operator bool() const
	{
		return m_name != nullptr;
	}
	Menuitem::operator const char* () const
	{
		return m_name;
	}
	ostream& Menuitem::display(ostream& os) const
	{
		os << m_name;
		return os;
	}
	void Menuitem::set(const char* name)
	{
		if (name != nullptr)
		{
			m_name = U.aloCopy(name);
		}
	}
	Menuitem::~Menuitem() {
		delete[] m_name;
	}

	// Menu methods
	Menu::Menu() {
		m_title.m_name = nullptr;
		m_size = 0;
		m_items[0] = nullptr;
	}
	Menu::Menu(const char* title) {
		m_title.set(title);
		m_size = 0;
		m_items[0] = nullptr;
	}

	std::ostream& Menu::displayTitle(std::ostream& os) const
	{
		if (m_title)
		{
			m_title.display(os);
		}
		return os;
	}

	std::ostream& Menu::display(std::ostream& os) const
	{
		if (*this)
		{
			if (m_title != nullptr) {
				m_title.display(os) << ":" << endl;
			}
			for (int i = 0; i < m_size; i++)
			{
				os.width(2);
				os.setf(ios::right);
				os << i+1 << "- ";
				(* m_items[i]).display(os);
				os << endl;
			}
			os << " 0- Exit" << endl;
			os << "> ";
		}
		return os;
	}

	unsigned int Menu::run() const
	{
		unsigned int selection;
		display();
		selection = U.getNumberInRange(0, m_size);
		return selection;
	}

	unsigned int Menu::operator~() const
	{
		return run();
	}

	Menu& Menu::operator<<(const char* menuitemConent)
	{
		if (m_size != MAX_MENU_ITEMS)
		{
			m_items[m_size] = new Menuitem(menuitemConent);
			m_size++;
		}
		return *this;
	}

	Menu::operator int()const {
		return m_size;
	}
	Menu::operator unsigned int()const {
		return (unsigned int)m_size;
	}
	const char* Menu::operator[](int index) const
	{
		return (const char*)(* m_items[index % m_size]);
	}
	Menu::operator bool()const {
		return m_size > 0;
	}
	Menu::~Menu()
	{
		for (int i = 0; i < m_size; i++)
		{
			delete m_items[i];
		}
	}

	
	std::ostream& operator<<(std::ostream& left, const Menu& right)
	{
		right.displayTitle(left);
		return left;
	}

}
