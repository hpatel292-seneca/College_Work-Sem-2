#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include<iostream>
namespace sdds
{
	class Streamable
	{
	public:
		virtual std::ostream& write(std::ostream& os = std::cout)const = 0;
		virtual std::istream& read(std::istream& is = std::cin)= 0;
		virtual bool conIO(std::ios&)const = 0;
		virtual operator bool()const = 0;
		virtual ~Streamable() {}
	};
	std::ostream& operator<< (std::ostream& left, const Streamable& right);
	std::istream& operator>> (std::istream& left, Streamable& right);
}
#endif // !SDDS_STREAMABLE_H