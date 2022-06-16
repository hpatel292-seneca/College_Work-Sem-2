/*
*****************************************************************************
						  Workshop - #3 (W3P2)
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
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "Bar.h"
using namespace std;
namespace sdds
{
	void Bar::set()
	{
		m_fill = '\0';
		m_value = 0;
		m_title = nullptr;
		m_valid = false;
	}
	void Bar::set(const char Bar_title[], char fill_char, int fill_value)
	{
		if (fill_value <= max_value && fill_value >= min_value && Bar_title != nullptr) {
			m_title = new char[strlen(Bar_title) + 1];
			strcpy(m_title, Bar_title);
			m_fill = fill_char;
			m_value = fill_value;
			m_valid = true;
		}
		else {
			m_valid = false;
			set();
		}
	}
	bool Bar::isvalid() const
	{
		return m_valid;
	}
	void Bar::printgraph(char fill, int times) const
	{
		printline(fill, times);
	}
	void Bar::draw() const
	{
		if (m_valid)
		{
			cout.setf(ios::left);
			cout.width(20);
			cout.fill('.');
			cout << m_title;
			cout.unsetf(ios::left);
			cout << "|";
			printgraph(m_fill, m_value / 2);
		}
	}

	void Bar::deallocate()
	{
		delete m_title;
		m_title = nullptr;
	}
	void printline(char fill, int times)
	{
		for (int i = 0; i < times; i++)
		{
			cout << fill;
		}
		cout << endl;
	}
}
