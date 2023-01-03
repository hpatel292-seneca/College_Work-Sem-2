#include<iostream>
#include"Student.h"
using namespace std;

Student::Student(int num, float* grades, int ng_){
    cout<<"Entering 3 args consturctor"<<endl;
    set(num, grades, ng_);
}

void Student::set(int student_num, float* grades, int ng_){
    ng = ng_ < 20? ng_:20;
    bool valid;

    if (student_num < 1){
        valid = false;
    }
    else{
        for(int i = 0; i < ng; i++){
            valid = grades[i] <= 100 && grades[i] >= 0; 
        }
    }
    if(valid){
        if(ng > 0){
            grade = new float[ng];
        }
        else{
            grade = nullptr;
        }
        if(student_num != 0 && grades != nullptr && ng != 0){
            num = student_num;

            for (int i = 0; i < ng; i++){
                grade[i] = grades[i];
            } 
        }
    }
    else{
        num = 0;
        ng = 0;
        grade = nullptr;
    }
}

Student::Student(){
    num = 0;
    ng = 0;
    grade = nullptr;
}

void Student::display() const{
    if(num > 0){
    cout<<"Student Number: " << num << endl;
    cout << "Grades:- "<<endl;
    for (int i = 0; i < ng; i++){
        cout <<grade[i] <<endl;
    }}
    else{
        cout<<"No data avalible!!";
    }
    cout << endl << endl;
}

Student::~Student(){
    cout<<"Destructor called"<<endl;
    delete[] grade;
}

void Student::read(){
    int num;
    float grade[20];
    int ng;

    cout<<"Enter the Student Number: ";
    cin >> num;
    cout<<"Enter number of Grades: ";
    cin >> ng;

    if (ng > 20) ng = 20;

    for(int i = 0; i < ng; i++){
        cout<<"Enter the Grades: ";
        cin >> grade[i];
    }

    Student temp(num, grade, ng);

    if (temp.num != 0)
        *this = temp;
}
Student::Student(const Student& src){
    num = src.num;
    ng = src.ng;

    if(src.grade != nullptr){
        grade = new float[ng];

        for(int i = 0; i < ng; i++){
            grade[i] = src.grade[i];
        }
    }
    else{
        grade = nullptr;
    }
}

Student& Student::operator=(const Student& src){
    if(this != &src){
        delete[] grade;
        num = src.num;
        ng = src.ng;

        if(src.grade != nullptr){
            grade = new float[ng];

            for(int i = 0; i < ng; i++){
                grade[i] = src.grade[i];
            }
        }
        else{
            grade = nullptr;
        }
    }
    return *this;
}