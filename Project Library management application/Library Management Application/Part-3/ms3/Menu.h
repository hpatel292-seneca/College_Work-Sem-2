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

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include<iostream>
namespace sdds
{
	const unsigned int MAX_MENU_ITEMS = 20;
	class Menuitem
	{
		friend class Menu;
		char* m_name{};
		Menuitem();
		Menuitem(const char* name);
		Menuitem(const Menuitem& item) = delete;
		Menuitem& operator = (const Menuitem& item) = delete;

		// Type conversion methods
		operator bool()const;
		operator const char* ()const;

		std::ostream& display(std::ostream& os)const;
		void set(const char* name);

		//destructor
		~Menuitem();
	};

	class Menu
	{
		Menuitem m_title;
		Menuitem* m_items[MAX_MENU_ITEMS];
		int m_size{};
	public:
		// Constructor
		Menu();
		Menu(const char* title);


		// NO copy and Assisnment
		Menu(const Menu&) = delete;
		Menu& operator = (const Menu&) = delete;

		// Methods
		// come back here can i do casting instead of writiting the displaytitle function
		std::ostream& displayTitle(std::ostream& os = std::cout)const;
		std::ostream& display(std::ostream& os = std::cout)const;
		unsigned int run()const;
		Menu& setTitle(const char* title);

		//operator overload
		unsigned int operator~()const;
		Menu& operator<<(const char* menuitemConent);

		//Type Conversion Operator
		operator int()const;
		operator unsigned int()const;
		operator bool()const;
		const char* operator[](int index)const;

		// destructor
		~Menu();
	};
	// helper functions
	std::ostream& operator<<(std::ostream& left, const Menu& right);
}
#endif // !SDDS_MENU_H
