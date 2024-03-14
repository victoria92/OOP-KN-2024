#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Queue.h"
#include"Queue.cpp"
using namespace std;

class Person {
private:
    char* name;
    int age;
    char gender;
    void copy(const Person& p) {
        name = new char[strlen(p.name)+1];
        strcpy(name, p.name);
        age = p.age;
        gender = p.gender;
    }
    void del() {
        delete[] name;
    }
public:
    Person(char* n, char g, int a = 0) :gender(g), age(a) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    Person(const Person& p) {
        copy(p);
    }
    ~Person() {
        del();
    }
    Person& operator=(const Person& p) {
        if (this != &p) {
            del();
            copy(p);
        }
        return *this;
    }
    int get_age() {
        return age;
    }
    bool set_age(int a) {
        if (a > 150) {
            return false;
        }
        age = a;
        return true;
    }
};
class Cabinet {
private:
    char* name;
    int room;
    Queue<Person*>* patients;
public:
    Cabinet(char* n, int r, int capacity):room(r) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        patients = new Queue<Person*>(10);
    }
};
class Hospital {
private:
    Cabinet cabinets[10];
};

int main() {
    char* n = new char[10];
    cin >> n;
    Person p(n, 'M');
    Queue<Person*> q(10);
    q.push(&p);
    p.set_age(15);
    Person* b;
    q.top(b);
    cout << b->get_age() << endl;
    return 0;
}