#ifndef SORTEDLIST_H
#define SORTEDLIST_H

template <typename T,bool sortMethod>
class SortedList {
public:
	SortedList();
	SortedList(T data);	
	void insert(SortedList<T, sortMethod> ** in, T price);
	T getHeadData();
	SortedList * getNext();
	void removeHead(SortedList ** in);
private:
	SortedList * next;
	T data;
	bool hasData;
};

#endif