#include<iostream>
#include "transaction.h"
using namespace std;

void enter(struct Transaction* tr){
    cout << "Enter the account Number: ";
    cin >> tr->acct;
    cout << "Enter the account type: ";
    cin >> tr->type;
    cout << "Enter the amount you want: ";
    cin >> tr->amount;
}

void display(const struct Transaction* tr){
    cout<<"The account Number is " << tr->acct <<endl;
    cout<< (tr->type == 'd' ? " Debit $" : " Credit $");
    cout<< tr->amount <<endl;
}