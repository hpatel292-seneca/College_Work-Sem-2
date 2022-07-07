#include<iostream>
#ifndef SDDS_BASKET_H_
#define SDD_BASKET_H_
namespace sdds
{
	struct Fruit
	{
		char m_name[30 + 1];
		double m_qty;
	};
	class Basket
	{
		Fruit* m_fruits{};
		int m_cnt{};
		double m_price{};
	public:
		Basket();
		Basket(Fruit fruits[], int size, double price);
		Basket(const Basket& source);
		Basket& operator=(const Basket& source);
		void init(const Basket& source);
		~Basket();
		void setPrice(double price);
		operator bool()const;
		Basket& operator+=(Fruit frt);
		friend std::ostream& operator<<(std::ostream& ostr, Basket& right);
	};

}

#endif // !SDDS_BASKET_H_