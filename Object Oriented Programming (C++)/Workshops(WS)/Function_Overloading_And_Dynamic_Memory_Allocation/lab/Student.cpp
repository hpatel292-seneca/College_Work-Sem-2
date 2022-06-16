#define _CRT_SECURE_NO_WARNINGS
#include"Student.h"
#include"File.h"
#include<iostream>
#include<cstring>
using namespace std;
namespace sdds
{
    Student* students;
    int noOfStudents;
    void sort() {
        int i, j;
        Student temp;
        for (i = noOfStudents - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (students[j].m_grade > students[j + 1].m_grade) {
                    temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
    }
    bool load(Student& student) {
        size_t Len_name;
        char temp_name[128];
        bool return_value = true;
        if (read(temp_name) == true) {
            Len_name = strlen(temp_name);
            student.m_name = new char[Len_name + 1];
            if (student.m_name == NULL) {
                cout << "out of space" << endl;
            }
            strcpy(student.m_name, temp_name);
            return_value = true;
        }
        else { return_value = false; }
        if (read(student.m_studentNumber) != true)
        {
            return_value = false;
        }
        if (read(student.m_grade) != true)
        {
            return_value = false;
        }
        return return_value;
    }
    bool load(const char filename[]) {
        bool return_value = true;
        if (openFile(filename) == true) {
            noOfStudents = noOfRecords();
            students = new Student[noOfStudents];
        }
        for (int i = 0; i < noOfStudents; i++)
        {
            if (load(students[i]) == false) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                i = noOfStudents;
                return_value = false;
            }
        }
        return return_value;
    }
    void display(Student& stud) {
        cout << stud.m_name << ", " << stud.m_studentNumber << ":" << stud.m_grade << endl;
    }
    void display()
    {
        sort();
        for (int i = 0; i < noOfStudents; i++)
        {
            cout << i + 1 << ": ";
            display(students[i]);
        }
    }
    void deallocateMemory() {
        for (int i = 0; i < noOfStudents; i++)
        {
            delete[] students[i].m_name;
        }
        delete[] students;
        closeFile();
        //students = NULL;
    }
}