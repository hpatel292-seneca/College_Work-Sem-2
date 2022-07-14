/*
*****************************************************************************
						  Workshop - #7
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
#include "Minister.h"
#include"Utils.h"
using namespace std;
namespace sdds
{
	Minister::Minister(const char* iid, int age, double year, const char* name, const char* district) : MemberParliament(iid, age)
	{
		U.strcpy(m_name, name);
		m_begin_year = year;
		this->NewDistrict(district);
	}
	void Minister::changePM(const char* pm)
	{
		U.strcpy(m_name, pm);
	}
	void Minister::assumeOffice(double year)
	{
		m_begin_year = year;
	}
	std::ostream& Minister::write(std::ostream& os)const
	{
		MemberParliament::write(os) << " | " << m_name << "/" << m_begin_year << endl;
		return os;
	}
	std::istream& Minister::read(std::istream& in)
	{
		MemberParliament::read(in);
		cout << "Reports TO: ";
		in >> m_name;
		cout << "Year Assumed Office: ";
		in >> m_begin_year;
		return in;
	}
	std::ostream& operator<<(std::ostream& left, const Minister& right)
	{
		right.write(left);
		return left;
	}
	std::istream& operator>>(std::istream& left, Minister& right)
	{
		right.read(left);
		return left;
	}
}
