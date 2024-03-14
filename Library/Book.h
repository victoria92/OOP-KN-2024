#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>


class Book {
private:
    char* name;
    int year;
    char* author;
public:
    Book(char*, int, char*);
    Book(const Book&);
    ~Book();
    Book& operator=(const Book&);
    char* get_name();
    int get_year();
    char* get_author();
};