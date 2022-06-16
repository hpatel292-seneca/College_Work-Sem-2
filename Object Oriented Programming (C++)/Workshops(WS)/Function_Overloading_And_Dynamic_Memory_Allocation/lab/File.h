#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();

   bool read(char* name);
   bool read(int& stud_number);
   bool read(char& grade);
}
#endif // !SDDS_FILE_H_
