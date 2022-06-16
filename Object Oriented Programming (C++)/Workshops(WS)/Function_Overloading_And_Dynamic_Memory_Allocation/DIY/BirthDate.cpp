/*
*****************************************************************************
						  Workshop - #3 (W2P2)
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
#include"BirthDate.h"
using namespace std;
namespace sdds
{
	// 999 because in instruction it is mentioned that records can be hundreads
	const int MaxEmployees = 999;
	Employee employees[MaxEmployees];
	// this will store actual number of record which is useful while printing data
	int noOfRecords = 0;
	FILE* fptr;
	bool beginSearch(const char* filename) {
		cout << "Birthdate search program" << endl;
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}
	bool readName(char* name) {
		return fscanf(fptr, "%[^,],", name) == 1? true: false;
	}
	bool readDate(Date& date) {
		return fscanf(fptr, "%d/%d/%d\n", &date.m_month, &date.m_date, &date.m_year) == 3 ? true : false;
	}
	bool readBirthDate(int month) {
		char name[31];
		Date tmp{0};
		noOfRecords = 0;
		size_t len_name;
		int i = 0;
		while (!feof(fptr))
		{
			if (readName(name) == true && readDate(tmp) == true) {
				if (tmp.m_month == month)
				{
					len_name = strlen(name);
					employees[i].m_name = new char[len_name + 1];
					strcpy(employees[i].m_name, name);
					employees[i].m_date = tmp;
					i++;
				}
			}
		}
		noOfRecords = i;
		return i>=1? true: false;
	}
	void sort() {
		int i, j;
		Employee tmp;
		for (i = noOfRecords-1; i > 0; i--)
		{
			for ( j = 0; j < i ; j++)
			{
				if (employees[j].m_date.m_year > employees[j+1].m_date.m_year)
				{
					tmp = employees[j];
					employees[j] = employees[j + 1];
					employees[j +1] = tmp;
				}
			}
		}
	}
	void displayBirthdays() {
		cout << noOfRecords << " birthdates found" << endl;
		for (int i = 0; i < noOfRecords; i++)
		{
			cout << i+1 << ") " 
				 << employees[i].m_name << ":" << endl 
				 << employees[i].m_date.m_year << "-" 
				 << employees[i].m_date.m_month << "-" 
				 << employees[i].m_date.m_date << endl;
			cout << "===================================" << endl;
		}
	}
	void deallocate() {
		for (int i = 0; i < noOfRecords; i++)
		{
			delete[] employees[i].m_name;
		}
	}
	void endSearch() {
		fclose(fptr);
		cout << "Birthdate Search Program Closed." << endl;
	}

}