/*
*****************************************************************************
						  Workshop - #3 (W3P2)
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
#include<cstring>
#include"Utils.h"
#include"Car.h"
using namespace std;
namespace sdds
{
	void Car::resetInfo()
	{
		m_brand = m_model = m_type = nullptr;
		m_code = m_price = m_year = 0;
	}
	Car::Car()
	{
		resetInfo();
	}
	Car::Car(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		if (type != nullptr && brand != nullptr && model != nullptr && year >= 1990 && code > 99 && code < 1000 && price > 0)
		{
			m_type = U.aloCopy(type);
			m_brand = U.aloCopy(brand);
			m_model = U.aloCopy(model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else {
			resetInfo();
		}
	}
	Car::~Car()
	{
		deallocate();
	}
	Car& Car::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		deallocate();
		if (type != nullptr && brand != nullptr && model != nullptr && year >= 1990 && code > 99 && code < 1000 && price > 0)
		{
			m_type = U.aloCopy(type);
			m_brand = U.aloCopy(brand);
			m_model = U.aloCopy(model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else {
			resetInfo();
		}
		return (*this);
	}
	void Car::deallocate()
	{
		delete[] m_type;
		delete[] m_model;
		delete[] m_brand;
	}
	void Car::printInfo() const
	{
		cout << "| ";
		cout.setf(ios::left);
		cout.width(10);
		cout << m_type;
		cout << " | ";
		cout.width(16);
		cout << m_brand;
		cout << " | ";
		cout.width(16);
		cout << m_model << " | " << m_year << " |  " << m_code << " |  ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout.width(8);
		cout.unsetf(ios::left);
		cout << m_price <<" | "<< endl;
		cout.unsetf(ios::fixed);
		
	}
	bool Car::isValid() const
	{
		bool valid{};
		if (m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && m_code > 99 && m_code < 1000 && m_price > 0)
		{
			valid = true;
		}
		return valid;
	}
	bool Car::isSimilarTo(const Car& car) const
	{
		return (m_type == car.m_type && m_model == car.m_model && m_brand == car.m_brand && m_year == car.m_year && m_code == car.m_code && m_price == car.m_price);
	}
	bool has_similar(const Car car[], const int num_cars)
	{
		bool isSimilar{};
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					isSimilar = true;
				}
			}
		}
		return isSimilar;
	}
	bool has_invalid(const Car car[], const int num_cars)
	{
		bool invalidCar = false;
		for (int i = 0; i < num_cars; i++)
		{
			if (car[i].isValid() == false)
			{
				invalidCar = true;
			}
		}
		return invalidCar;
	}
	void print(const Car car[], const int num_cars)
	{
		for (int i = 0; i < num_cars; i++)
		{
			if (car[i].isValid())
			{
				car[i].printInfo();
			}
		}
	}
}