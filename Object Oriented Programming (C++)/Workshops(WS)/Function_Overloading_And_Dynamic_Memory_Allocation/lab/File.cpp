#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<cstring>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   bool read(char* name) {
	   bool m_return_value = false;
	   if (fscanf(fptr, "%[^,],", name) == 1)
	   {
		   m_return_value = true;
	   }
	   return m_return_value;
   }

   bool read(int& stud_number) {
	   bool m_return_value = false;
	   if (fscanf(fptr, "%d,", &stud_number) == 1)
	   {
		   m_return_value = true;
	   }
	   return m_return_value;
   }

   bool read(char& grade) {
	   bool m_return_value = false;
	   if (fscanf(fptr, "%c\n", &grade) == 1)
	   {
		   m_return_value = true;
	   }
	   return m_return_value;
   }
}