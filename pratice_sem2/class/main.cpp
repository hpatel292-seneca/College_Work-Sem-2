#include<iostream>
#include"Student.h"
using namespace std;

int main () {
     float gh[] = {89.4f, 67.8f, 45.5f};
     Student harry(1234, gh, 3);
     harry.display();
 }