#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include"Publication.h"

namespace sdds
{
	class Book : public Publication
	{
		char* m_author{};
	public:
		Book(){}
		Book(const Book& book);
		Book& operator=(const Book& book);
		~Book();
		char type()const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		void set(int member_id);
		operator bool() {
			bool ret{};
			if (Publication::operator bool())
			{
				if (m_author)
				{
					ret = true;
				}
			}
			return ret;
		}
	};

}
#endif // !SDDS_BOOK_H