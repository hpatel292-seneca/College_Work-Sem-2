#include<iostream>
using namespace std;

struct Student{
    int num;
    float grade[2];
};

int main(){
    int n;
    cout<<"Enter the Number of the student: ";
    cin >> n;

    Student* students = new Student[n];

    for(int i = 0; i < n; i++){
        cout<<"Please enter the Student Number of Student "<<i<<" : ";
        cin >> students[i].num;
        cout<<"Please enter the 1st Grade of Student "<<i<<" : ";
        cin >> students[i].grade[0];
        cout<<"Please enter the 2nd Grade of Student "<<i<<" : ";
        cin >> students[i].grade[1];
    }

    for(int i = 0; i < n; i++){
        cout<<"Student Num: "<<students[i].num<<endl;
        cout<<"Student's 1st Grade: "<<students[i].grade[0]<<endl;
        cout<<"Student's 2nd Grade: "<<students[i].grade[1]<<endl;
    }

    delete[] students;
    students = nullptr;
}