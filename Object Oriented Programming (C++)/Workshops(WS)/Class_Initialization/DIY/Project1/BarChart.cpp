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
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "BarChart.h"
#include"Bar.h"
using namespace std;
namespace sdds
{
	bool BarChart::isChartValid()
	{
		bool valid = true;
		for (int i = 0; i < m_no_bars && valid; i++)
		{
			(!m_bars[i].isvalid()) && (valid = false);
		}
		return valid;
	}
	void BarChart::init(const char* title, int noOfSamples, char fill)
	{
		if (title != nullptr && noOfSamples > 0 && fill != '\n')
		{
			m_bars = new Bar[noOfSamples];
			m_chart_title = new char[strlen(title) + 1];
			strcpy(m_chart_title, title);
			m_totalNumBars = noOfSamples;
			m_fill = fill;
			m_no_bars = 0; 
		}
		else {
			m_bars = nullptr;
			m_chart_title = nullptr;
			m_totalNumBars = 0;
			m_no_bars = 0;
		}
	}
	void BarChart::add(const char* bar_title, int value)
	{
		if (m_no_bars <= m_totalNumBars && value >= min_value && value <= max_value && bar_title != nullptr)
		{
			m_bars[m_no_bars].set(bar_title, m_fill, value);
			m_no_bars++;
		}
	}
	void BarChart::draw()
	{
		if (isChartValid() && m_no_bars == m_totalNumBars)
		{
			cout << m_chart_title << endl; 
			printline('-', 71);
			for (int i = 0; i < m_no_bars; i++)
			{
				m_bars[i].draw();
			}
			printline('-', 71);
		}
		else {
			cout << "Invalid Chart!" << endl;
		}
	}
	void BarChart::deallocate()
	{
		for (int i = 0; i < m_no_bars; i++)
		{
			m_bars[i].deallocate();
		}
		delete m_chart_title;
		delete[] m_bars;
		m_chart_title = nullptr;
		m_bars = nullptr;
	}
}
