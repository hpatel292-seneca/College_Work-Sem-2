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
#include "MemberParliament.h"
#include"Utils.h"
using namespace std;
namespace sdds
{
	MemberParliament::MemberParliament(const char* id, int age)
	{
		U.strcpy(m_district, "Unassigned");
		U.strcpy(m_id, id);
		m_age = age;
	}
	void MemberParliament::NewDistrict(const char* district)
	{
		cout << "|";
		cout.setf(ios::right);
		cout.width(8);
		cout << m_id << "| |";
		cout.width(20);
		cout << m_district << " ---> ";
		cout.unsetf(ios::right);
		cout.setf(ios::left);
		cout.width(23);
		cout << district << "|" << endl;
		U.strcpy(m_district, district);
	}
	ostream& MemberParliament::write(ostream& os) const
	{
		os << " " << m_id << " | " << m_age << " | " << m_district;
		return os;
	}
	std::istream& MemberParliament::read(std::istream& in)
	{
		cout << "MP Age: ";
		in >> m_age;
		cout << "MP Id: ";
		in >> m_id;
		cout << "District: ";
		in >> m_district;
		return in;
	}
	std::ostream& operator<<(std::ostream& left, const MemberParliament& right)
	{
		right.write(left);
		return left;
	}
	std::istream& operator>>(std::istream& left, MemberParliament& right)
	{
		right.read(left);
		return left;
	}
}