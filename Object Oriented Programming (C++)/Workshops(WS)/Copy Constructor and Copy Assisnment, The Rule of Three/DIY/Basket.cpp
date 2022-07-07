#include<iostream>
#include "Basket.h"
using namespace std;
namespace sdds
{
	Basket::Basket()
	{
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0.0;
	}

	Basket::Basket(Fruit fruits[], int size, double price)
	{
		m_cnt = size;
		m_price = price;
		if (fruits != nullptr)
		{
			m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < m_cnt; i++)
			{
				m_fruits[i] = fruits[i];
			}
		}
		else {
			m_fruits = nullptr;
		}
		/*init(fruits, size, price);*/
	}

	Basket::Basket(const Basket& source)
	{
		init(source);
	}

	Basket& Basket::operator=(const Basket& source)
	{
		if (this != &source)
		{
			delete[] m_fruits;
			init(source);
		}
		return *this;
	}

	void Basket::init(const Basket& source)
	{
		m_cnt = source.m_cnt;
		m_price = source.m_price;
		if (source.m_fruits != nullptr)
		{
			m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < m_cnt; i++)
			{
				m_fruits[i] = source.m_fruits[i];
			}
		}
		else {
			m_fruits = nullptr;
		}
	}
	Basket::~Basket()
	{
		delete[] m_fruits;
	}
	void Basket::setPrice(double price)
	{
		if (price != 0.0)
		{
			m_price = price;
		}
	}
	Basket::operator bool() const
	{
		return m_cnt > 0;
	}
	Basket& Basket::operator+=(Fruit frt)
	{
		Fruit* tmp = new Fruit[m_cnt + 1];
		for (int i = 0; i < m_cnt; i++)
		{
			tmp[i] = m_fruits[i];
		}
		tmp[m_cnt] = frt;
		delete[] m_fruits;
		m_fruits = tmp;
		m_cnt++;
		return *this;
	}
	ostream& operator<<(ostream& ostr, Basket& right)
	{
		if (right.m_cnt == 0)
		{
			ostr << "The basket is empty!" << endl;
		}
		else {
			ostr << "Basket Content:" << endl;
			for (int i = 0; i < right.m_cnt; i++)
			{
				ostr.setf(ios::fixed);
				ostr.precision(2);
				ostr.width(10);
				ostr.setf(ios::right);
				ostr << right.m_fruits[i].m_name << ": " << right.m_fruits[i].m_qty << "Kg" << endl;
			}
			ostr << "Price: " << right.m_price << endl;
		}
		return ostr;
	}
}
