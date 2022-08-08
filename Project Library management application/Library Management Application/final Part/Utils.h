/* Citation and Sources...
Final Project Milestone 1
Module: utils
Filename: utils.h
Version 1.0
Author	Harshil Patel(148847213)
Revision History
-----------------------------------------------------------
Date: 2022/7/7
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#pragma once
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include <iostream>
using namespace std;
namespace sdds
{
    class Utils
    {
    public:
        int strlen(const char* cString)const;
        void strcpy(char* cStrDes, const char* cStrSrc, int len = -1);
        int getInt(const char* prompt = nullptr);
        int getIntInRange(int max, int min);
        double getDouble(const char* prompt = nullptr);
        char* readDyncStr(std::istream& istr = std::cin, char delimiter = '\n');
        char* aloCopy(const char* src);
        unsigned int getNumberInRange(unsigned int min, unsigned int max);
        char* readDyncStrLen(std::istream& istr = std::cin, int maxLen = 1024);
        void writeWithLen(ostream& ostr, const char* str, int len = -1, const char fill = ' ');
        const char* strstr(const char* str, const char* find)const;
        int strcmp(const char* s1, const char* s2, int len = -1)const;
    };
    extern Utils U; // globalize the file scoped U in utils.cpp

}
#endif // !SDDS_UTILS_H


