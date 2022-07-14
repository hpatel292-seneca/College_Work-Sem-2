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

#ifndef SDDS_MEMEBRPARLIAMENT_H
#define SDDS_MEMEBRPARLIAMENT_H
#define MAXIDLEN 32
#define MAXNAMELEN 64
#include<iostream>
namespace sdds
{
	class MemberParliament
	{
		char m_id[MAXIDLEN];
		char m_district[MAXNAMELEN];
		int m_age;
	public:
		MemberParliament(const char* id, int age);
		void NewDistrict(const char* district);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& left, const MemberParliament& right);
	std::istream& operator>>(std::istream& left, MemberParliament& right);
}
#endif // !SDDS_MEMEBRPARLIAMENT_H