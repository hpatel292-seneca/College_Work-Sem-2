#include "Streamable.h"
namespace sdds
{
	std::ostream& operator<<(std::ostream& left, Streamable& right)
	{
		if ((bool)right)
		{
			right.write(left);
		}
		return left;
	}
	std::istream& operator>>(std::istream& left, Streamable& right)
	{
		right.read(left);
		return left;
	}
}