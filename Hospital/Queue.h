#pragma once
template <typename T>
class Queue {
private:
	//TODO: change this to T**
	T* elements;
	int capacity;
	int size;
public:
	Queue(int);
	Queue(const Queue&);
	~Queue();
	Queue& operator=(const Queue&);
	bool top(T&);
	bool pop();
	bool push(T);
};