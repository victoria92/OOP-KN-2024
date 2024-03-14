#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;


class Person {
private:
    char* name;
    int age;
    char gender;
    void copy(const Person& p);
    void del();
public:
    Person(char* n, char g, int a = 0);
    Person(const Person& p);
    ~Person();
    Person& operator=(const Person& p); 
    int get_age();
    bool set_age(int a);
    friend ostream& operator<<(ostream&, const Person&);
};
