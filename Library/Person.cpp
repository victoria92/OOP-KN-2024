#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "Person.h"


void Person::copy(const Person& p) {
    name = new char[strlen(p.name)+1];
    strcpy(name, p.name);
    age = p.age;
    gender = p.gender;
}

void Person::del() {
    delete[] name;
}

Person::Person(char* n, char g, int a) :gender(g), age(a) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}
Person::Person(const Person& p) {
    copy(p);
}
Person::~Person() {
    del();
}
Person& Person::operator=(const Person& p) {
    if (this != &p) {
        del();
        copy(p);
    }
    return *this;
}
int Person::get_age() {
    return age;
}
bool Person::set_age(int a) {
    if (a > 150) {
        return false;
    }
    age = a;
    return true;
}

ostream& operator<<(ostream& out, const Person& p) {
    out << p.name << endl;
    out << p.age << endl;
    return out;
}
