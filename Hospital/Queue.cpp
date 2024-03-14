#include "Queue.h"

template <typename T>
Queue<T>::Queue(int c) {
	capacity = c;
	size = 0;
	elements = new T[capacity];
}

template <typename T>
Queue<T>::Queue(const Queue<T>& q) {
	capacity = q.capacity;
	size = q.size;
	elements = new T[q.capacity];
}

template <typename T>
Queue<T>::~Queue() {
	delete[] elements;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& q) {
	if (this != &q) {
		delete[] elements;
		capacity = q.capacity;
		size = q.size;
		elements = new T[q.capacity];
	}
	return *this;
}

template <typename T>
bool Queue<T>::top(T& x) {
	if (size > 0) {
		x = elements[0];
		return true;
	}
	return false;
}

template <typename T>
bool Queue<T>::pop() {
	if (size > 0) {
		size--;
		for (int i = 0; i < size; i++) {
			elements[i] = elements[i + 1];
		}
		return true;
	}
	return false;
}

template <typename T>
bool Queue<T>::push(T x) {
	if (size < capacity) {
		elements[size] = x;
		size++;
		return true;
	}
	return false;
}