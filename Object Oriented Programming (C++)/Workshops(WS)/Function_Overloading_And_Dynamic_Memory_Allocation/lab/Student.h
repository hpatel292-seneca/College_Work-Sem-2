#ifndef _SDDS_STUDENT_H
#define _SDDS_STUDENT_H
namespace sdds
{
    struct Student
    {
        char* m_name;
        int m_studentNumber;
        char m_grade;
    };
    void sort();
    bool load(Student& student);
    bool load(const char filename[]);
    void display(Student& stud);
    void display();
    void deallocateMemory();
}

#endif // !_SDDS_STUDENT_H
