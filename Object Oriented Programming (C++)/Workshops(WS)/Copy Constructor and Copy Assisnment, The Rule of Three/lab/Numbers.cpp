#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include "Numbers.h"  // intentional
using namespace std;
namespace sdds {

  
   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
         sort();
      }
   }
   Numbers::Numbers(const Numbers& obj)
   {
       setEmpty();
       m_isOriginal = false;
       *this = obj;
   }
   Numbers& Numbers::operator=(const Numbers& obj)
   {
       if (this != &obj)
       {
           delete[] m_numbers;
           m_numCount = obj.m_numCount;
           m_numbers = new double[obj.m_numCount];
           for (int i = 0; i < m_numCount; i++)
           {
               m_numbers[i] = obj.m_numbers[i];
           }
       }
       else {
           setEmpty();
       }
       return *this;
   }
   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }
   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   int Numbers::numberCount() const
   {
       int num_lines = 0;
       ifstream file(m_filename);
       if (file.is_open())
       {
           while (!file.fail()) {
               char c;
               file.get(c);
               if (c == '\n') {
                   if (!file.fail())
                   {
                       num_lines++;
                   }
               }
           }
           //come here back!!!!!!!!!
           file.close();
       }
       return num_lines;
   }
   bool Numbers::load()
   {
       bool retvalue = false;
       int counter = 0;
       if (m_numCount > 0)
       {
           m_numbers = new double[m_numCount];
           ifstream file;
           file.open(m_filename);
           while (!file.fail())
           {
               file >> m_numbers[counter];
               counter++;
           }
           file.close();
           counter--;
       }
       if (counter == m_numCount)
       {
           retvalue = true;
       }
       return retvalue;
   }
   void Numbers::save()
   {
       if (m_isOriginal && !isEmpty())
       {
           ofstream file(m_filename);
           for (int i = 0; i < m_numCount; i++)
           {
               file << m_numbers[i] << '\n';
           }
           file.close();
       }
   }
   Numbers& Numbers::operator+=(const double& right)
   {
       if (!isEmpty())
       {
           double* tmp = new double[m_numCount + 1];
           for (int i = 0; i < m_numCount; i++)
           {
               tmp[i] = m_numbers[i];
           }
           tmp[m_numCount] = right;
           m_numCount++;
           delete[] m_numbers;
           m_numbers = tmp;
           sort();
       }
       return *this;
   }
   ostream& Numbers::display(ostream& ostr) const
   {
       if (isEmpty())
       {
           ostr << "Empty list";
       }
       else {
           ostr << "=========================" << endl;
           if (m_isOriginal)
           {
               ostr << m_filename << endl;
           }
           else {
               ostr << "*** COPY ***" << endl;
           }
           for (int i = 0; i < m_numCount-1; i++)
           {
               ostr << m_numbers[i] << ", ";
           }
           ostr << m_numbers[m_numCount - 1] << endl;
           ostr << "-------------------------" << endl;
           ostr << "Total of " << m_numCount << " number(s)" << endl;
           ostr << "Largest number:  " << max() << endl;
           ostr << "Smallest number: " << min() << endl;
           ostr << "Average :        " << average() << endl;
           ostr << "=========================";
       }
       return ostr;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }


   
   ostream& operator<<(ostream& os, const Numbers& N)
   {
       return N.display(os);
   }

   std::istream& operator>>(std::istream& istr, Numbers& N)
   {
       double number;
       istr >> number;
       N += number;
       return istr;
   }

}
