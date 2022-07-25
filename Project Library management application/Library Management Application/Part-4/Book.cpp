#include"iostream"
#include "Book.h"
#include"Utils.h"
#include"Lib.h"
using namespace std;
namespace sdds
{
	// i think the below function will set the parent data twice
	Book::Book(const Book& book) : Publication(book)
	{
		*this = book;
	}
	Book& Book::operator=(const Book& book)
	{
		if (this != &book) {
			Publication::operator=(book);
			delete[] m_author;
			m_author = U.aloCopy(book.m_author?book.m_author:"");
		}
		return *this;
	}
	Book::~Book()
	{
		delete[] m_author;
	}
	char Book::type() const
	{
		return 'B';
	}
	std::ostream& Book::write(std::ostream& os) const
	{
		Publication::write(os);
		if (conIO(os))
		{
			os << " ";
			os.width(SDDS_AUTHOR_WIDTH);
			os << m_author;
			os << " |";
		}
		else {
			os << '\t' << m_author;
		}
		return os;
	}
	std::istream& Book::read(std::istream& istr)
	{
		char author[256];
		Publication::read(istr);
		delete[] m_author;
		if (conIO(istr))
		{
			istr.get();
			cout << "Author: ";
			istr.getline(author, 256, '\n');
		}
		else {
			istr.ignore(1, '\t');
			istr.getline(author, 256, '\n');
		}
		if (istr)
		{
			m_author = U.aloCopy(author);
		}
		return istr;
	}
	void Book::set()
	{
		Publication::set();
		resetDate();
	}
}