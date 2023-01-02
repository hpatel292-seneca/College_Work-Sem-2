#include<iostream>
using namespace std;

struct Student{
    int num;
    char name[31];
    double grade;
};

int main(){
    const int num_student = 3;
    Student s1 = {1234, "john", 90.5};
    Student s2 = {1235, "shaw", 87.5};
    Student s3 = {1236, "michel", 78.5};
    Student* p_student[num_student];
    p_student[0] = &s1;
    p_student[1] = &s2;
    p_student[2] = &s3;

    for (int i = 0; i < num_student; i++){
        cout<<p_student[i]->num<<endl<<p_student[i]->name << endl << p_student[i]->grade<<endl;
        cout<<endl;
    }
}