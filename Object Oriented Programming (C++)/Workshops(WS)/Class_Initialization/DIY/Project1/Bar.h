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
*****************************************************************************
*/
#ifndef SDDS_BAR_H_
#define SDDS_BAR_H_
namespace sdds
{
	const int max_value = 100;
	const int min_value = 0;
	class Bar
	{
		char* m_title;
		int m_value;
		char m_fill;
		bool m_valid;
	public:
		void set();
		void set(const char Bar_title[], char fill_char, int fill_value);
		bool isvalid() const;
		void draw() const;
		void deallocate();
		void printgraph(char fill, int times) const;
	};
	void printline(char fill, int times);
}
#endif // !SDDS_BAR_H_


