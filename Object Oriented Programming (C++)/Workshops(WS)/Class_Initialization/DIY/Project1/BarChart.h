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
#ifndef SDDS_BARCHART_H_
#define SDDS_BARCHART_H_
namespace sdds
{
	class Bar;
	class BarChart
	{
		char* m_chart_title;
		Bar* m_bars;
		int m_no_bars;
		int m_totalNumBars;
		char m_fill;
	public:
		bool isChartValid();
		void init(const char* title, int noOfSamples, char fill);
		void add(const char* bar_title, int value);
		void draw();
		void deallocate();
	};
}
#endif
