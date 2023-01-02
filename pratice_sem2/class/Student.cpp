#include<iostream>
#include"Student.h"
using namespace std;
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
        if(student_num != 0 && grades != nullptr && ng != 0){
            num = student_num;

            for (int i = 0; i < ng; i++){
                grade[i] = grades[i];
            } 
        }
    }
    else{
        num = 0;
    }
}

void Student::display() const{
    if(num > 0){
    cout<<"Student Number: " << num << endl;
    cout << "Grades:- ";
    for (int i = 0; i < ng; i++){
        cout <<grade[i] << " ";
    }}
    else{
        cout<<"No data avalible!!";
    }
    cout << endl << endl;
}