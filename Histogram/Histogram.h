#pragma once
#include<iostream>
using namespace std;

template <typename K>
struct pair {
	K key;
	int value;
}

template <typename K>
class Histogram {
    private:
	pair<k>* elements;
	int size;
    public:
	Histogram();
	Histogram(K* keys, int size);
	Histogram(const Histogram&);
	~Histogram();
	Histogram& operator=(const Histogram&);
	int operator[](K key);
	Histogram operator+(const Histogram&);
	Histogram& operator+=(const Histogram&);
	friend ostream& operator<<(ostream& out, const Histogram&);
};

