#include<iostream>
#include"Student.h"
using namespace std;

int main(){
    float grades[] = {12.45, 32, 34.6, 67};
    Student s1;
    s1.set(-1, grades, 4);
    s1.display();
}