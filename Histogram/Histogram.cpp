#include "Histogram.h"

template <typename K>
Histogram::Histogram() {
	elements = NULL;
	size = 0;
}

template <typename K>
Histogram::Histogram(K* keys, int size) {
	for(int i=0; i < size; i++) {
		for(int j=0; j < this->size; j++) {
			if(keys[i] == elements[j].key) {
				elements[j].value++;
				break;
			}
			pair<K> p = new pair<K>(keys[i], 1);
			pair<K>* new_elements = new pair<K>[this->size];
			for(int l=0; l<this->size; l++) {
				new_elements[l] = this->elements[l];
			}
			delete[] elements;
			this->size++;
			elements = new pair<K>[this->size];
			for(int l=0; l<this->size-1; l++) {
				new_elements[l] = this->elements[l];
			}
			this->elements[this->size-1] = p;
		}
	}
}

template <typename K>
Histogram::Histogram(const Histogram& h) {
	this->size = h.size;
	this->elemtns = new pair<K>[this->size];
	for(int i=0; i<this->size; i++) {
		elements[i].key = h.elements[i].key;
		elements[i].value = h.elements[i].value;
	}
}

template <typename K>
Histogram::~Histogram() {
	delete[] elements;
}





