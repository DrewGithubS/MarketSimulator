#include "SortedList.hpp"
#include <cstdlib>
#include <cstdio>

template<typename T, bool sortMethod>
SortedList<T, sortMethod>::SortedList() {
	next = 0;
	hasData = false;
}

template<typename T, bool sortMethod>
SortedList<T, sortMethod>::SortedList(T dataIn) {
	next = 0;
	data = dataIn;
	hasData = true;
}

template<typename T, bool sortMethod>
bool compare(T a, T b) {
	return (a > b) ^ sortMethod;
}

template<typename T, bool sortMethod>
void SortedList<T, sortMethod>::insert(SortedList<T, sortMethod> ** in, T dataIn) {
	SortedList * next = this;
	if(!next->hasData) {
		next->data = dataIn;
		next->hasData = true;
		return;
	}

	if(!compare<T, sortMethod>(dataIn, data)) {
		printf("NOW\n");
		SortedList<T, sortMethod> * temp = new SortedList<T, sortMethod>();
		temp->data = dataIn;
		temp->hasData = true;
		temp->next = this;
		*in = temp;
		return;
	}
	while(next->next != 0 && compare<T, sortMethod>(dataIn, next->next->data)) {
		next = next->next;
		if(!next->hasData) {
			next->data = dataIn;
			next->hasData = true;
			return;
		}
		printf("\t\tComparing %d and %d\n", dataIn, next->data);
		if(!next->hasData) {
			next->data = dataIn;
			next->hasData = true;
			return;
		}
	}

	SortedList<T, sortMethod> * temp = new SortedList<T, sortMethod>();

	temp->data = dataIn;
	temp->hasData = true;
	fflush(stdout);
	temp->next = next->next;
	next->next = temp;
}

template<typename T, bool sortMethod>
T SortedList<T, sortMethod>::getHeadData() {
	return data;
}

template<typename T, bool sortMethod>
SortedList<T, sortMethod> * SortedList<T, sortMethod>::getNext() {
	return next;
}

template<typename T, bool sortMethod>
void SortedList<T, sortMethod>::removeHead(SortedList ** in) {
	SortedList * temp = *in;
	(*in) = temp->next;
	free(temp);
}
