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
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
namespace sdds
{
	class Car
	{
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		void resetInfo();
	public:
		Car();
		Car(const char* type,
			const char* brand,
			const char* model,
			int year = 2022,
			int code = 100,
			double price = 1);
		~Car();
		Car& setInfo(const char* type,
			const char* brand,
			const char* model,
			int year,
			int code,
			double price);
		void deallocate();
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const Car& car) const;
	};
	bool has_similar(const Car car[], const int num_cars);
	bool has_invalid(const Car car[], const int num_cars);
	void print(const Car car[], const int num_cars);
}
#endif // !SDDS_CAR_H
