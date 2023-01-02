#include<iostream>
using namespace std;

//prototype
void display(int);
void display(int*, int);
int main(){
    int i[] = {1,2,3,4,5,6,7,8};
    display(10);
    display(i, 8);
}

void display(int num){
    cout << num;
}

void display(int* num, int count){
    for(int i = 0; i < count; i++){
        cout<<num[i] << " ";
    }
}