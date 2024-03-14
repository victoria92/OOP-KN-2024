#include<iostream>
#include "Person.h"
using namespace std;

int main() {
    char* name = new char[20];
    cin >> name;
    Person p(name, 'M', 15);
    cout << p;
    return 0;
}