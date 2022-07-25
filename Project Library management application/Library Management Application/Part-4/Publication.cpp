#include<iostream>
#include<cstring>
#include"Utils.h"
#include"Lib.h"
#include "Publication.h"
using namespace std;
namespace sdds
{
	void Publication::set()
	{
		m_title = nullptr;
		m_shelfld[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date.setToToday();
	}
	Publication::Publication()
	{
		set();
		// all member variables i have already set to default at the time of creation
	}
	void Publication::set(int member_id)
	{
		if (member_id > 9999 && member_id < 100000) {
			m_membership = member_id;
		}
	}
	void Publication::setRef(int value)
	{
		if (value > 0)
		{
			m_libRef = value;
		}
	}
	void Publication::resetDate()
	{
		m_date.setToToday();
	}
	char Publication::type() const
	{
		return 'P';
	}
	bool Publication::onLoan() const
	{
		return m_membership != 0;
	}
	Date Publication::checkoutDate() const
	{
		return m_date;
	}
	bool Publication::operator==(const char* title) const
	{
		return strstr(m_title, title);
	}
	Publication::operator const char* () const
	{
		return m_title;
	}
	int Publication::getRef() const
	{
		return m_libRef;
	}
	bool Publication::conIO(std::ios& io) const
	{
		return (&io == &cout ||&io == &cin);
	}
	std::ostream& Publication::write(std::ostream& os) const
	{
		if (conIO(os))
		{
			os << "| " << m_shelfld << " | ";
			os.setf(ios::fixed);
			os.width(30);
			os.fill('.');
			os.setf(ios::left);
			os << m_title << " | ";
			if (m_membership)
			{
				os << m_membership << " | ";
			}
			else {
				os << " N/A  | ";
			}
			m_date.write(os) << " |";
		}
		else {
			os << '\t' << type() << '\t' << m_libRef <<
				'\t' << m_shelfld << '\t' << m_title << '\t' << m_membership << '\t'; m_date.write(os);
		}
		return os;
	}
	std::istream& Publication::read(std::istream& istr)
	{
		delete[] m_title;
		set();
		char title[SDDS_TITLE_WIDTH]{};
		char shelfId[10];
		shelfId[0] = '\0';
		int membership{};
		int libRef = -1;
		Date date;
		if (conIO(istr))
		{
			cout << "Shelf No: ";
			istr.getline(shelfId, 10, '\n');
			if (U.strlen(shelfId) != 4)
			{
				istr.setstate(ios_base::failbit);
			}
			cout << "Title: ";
			istr.getline(title, 30, '\n');
			cout << "Date: ";
			date.read(istr);
		}
		else {
			istr >> libRef;
			istr.ignore(5, '\t');
			istr.getline(shelfId, 5, '\t');
			istr.getline(title, 30, '\t');
			istr >> membership;
			istr.ignore(5, '\t');
			date.read(istr);
			/*istr >> libRef;
			istr.get();
			istr >> shelfId;
			if (U.strlen(shelfId) != 4)
			{
				istr.setstate(ios_base::failbit);
			}
			istr.get();
			istr.getline(title, SDDS_TITLE_WIDTH,'\t');
			istr >> membership;
			istr.get();
			date.read(istr);*/
		}
		if (date.errCode() != 0)
		{
			istr.setstate(ios_base::failbit);
		}
		if (istr)
		{
			int title_len = U.strlen(title);
			m_title = new char[title_len + 1];
			U.strcpy(m_title, title);
			U.strcpy(m_shelfld, shelfId);
			m_membership = membership;
			m_date = date;
			m_libRef = libRef;
		}
		return istr;
	}
	Publication::operator bool() const
	{
		return (m_title != nullptr && m_shelfld != nullptr);
	}
	Publication::Publication(const Publication& pub)
	{
		init(pub);
	}
	Publication& Publication::operator=(const Publication& pub)
	{
		if (this != &pub)
		{
			delete[] m_title;
			init(pub);
		}
		return *this;
	}
	Publication::~Publication()
	{
		delete[] m_title;
	}
	void Publication::init(const Publication& scr)
	{
		m_date = scr.m_date;
		m_libRef = scr.m_libRef;
		m_membership = scr.m_membership;
		U.strcpy(m_shelfld, scr.m_shelfld);
		if (scr.m_title != nullptr)
		{
			m_title = new char[U.strlen(scr.m_title) + 1];
			U.strcpy(m_title, scr.m_title);
		}
		else {
			m_title = nullptr;
		}

	}
	
}