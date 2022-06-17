#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"

using namespace std;
namespace sdds {
	void Book::init_book() {
		m_title[0] = '\0';
		m_author[0] = '\0';
		m_num_chapters=0;
		m_num_pages=0;
	}

	int Book::add_chapter(const Chapter* chapter)
	{
		++(*this);
		m_chapters[m_num_chapters] = *chapter;
		return m_num_chapters;
	}

	Book::Book() {
		init_book();
	}

	Book::Book(const char* title_) {
		init_book();
		strcpy(m_title, title_);
	}

	Book::Book(const char* title_, const char* author_, double price_) {
		init_book();
		strcpy(m_title, title_);
		strcpy(m_author, author_);
		m_price = price_;
	}

	// Print a book summary
	void Book::summary() {
		cout.setf(ios::left);
		cout << "| ";
		cout.width(MAX_BOOK_TITEL);
		cout << m_title << " | ";
		cout.width(MAX_AUTHOR_NAME);
		cout << m_author << " | ";
		cout.width(3);
		cout << m_num_chapters << "  ";
		cout.width(4);
		cout << m_num_pages << " | ";
		cout.width(6);
		cout << m_price << " |" << endl;
	}

	Book& Book::operator++()
	{
		m_num_chapters++;
		return *this;
		// TODO: insert return statement here
	}

	std::ostream& Book::display(std::ostream& ostr) const
	{
		cout << "Title:'" << (const char*)*this <<"'"<< endl;
		cout << "Author: '"  << m_author << "'"<<endl;
		for (int i = 0; i < m_num_chapters; i++)
		{
			cout << "| Chapter " << i+1 << "  | ";
			cout.setf(ios::left);
			cout.width(MAX_CHAPTER_TITLE);
			cout << (const char*)m_chapters[i+1] << " |"<<endl;
		}
		return ostr;
	}

	Book::operator int() const
	{
		return m_num_chapters;
	}

	Book::operator bool() const
	{
		bool ret = false;
		if (m_title != 0 && m_author != 0 && m_num_chapters > 0)
		{
			for (int i = 0; i < m_num_chapters; i++)
			{
				if ((int)m_chapters[i] > 0)
				{
					ret = true;
				}
			}

		}
		return ret;
	}

	Book::operator double() const
	{
		return m_price;
	}

	Book::operator const char* () const
	{
		return m_title;
	}

	bool Book::operator!() const
	{
		return !(bool)*this;
	}

	Book& Book::operator+=(const Chapter& right)
	{
		add_chapter(&right);
		return *this;
	}

	Book& Book::operator-=(double amt)
	{
		m_price -= amt;
		return *this;
	}

	

	

	std::ostream& operator<<(std::ostream& left, const Book& right)
	{
		right.display(left);
		return left;
	}

}
