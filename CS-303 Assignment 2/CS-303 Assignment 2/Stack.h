// Stack.h
#ifndef STACK_H_
#define STACK_H_
#include "Namespace.h"

template<typename Item_type>

class Vstack {
private:
	AT::vector<Item_type> container;
	int total = 0;

public: 
	void push(const Item_type& item);
	Item_type& top();
	void pop();
	bool empty();
	size_t size();
	int average();

};

template<typename Item_type>
void Vstack<Item_type>::push(const Item_type& item) {
	total += item;
	container.push_back(item);
}

template<typename Item_type>
Item_type& Vstack<Item_type>::top() {
	return container.back();
}

template<typename Item_type>
void Vstack<Item_type>::pop() {
	total -= container.back();
	container.pop_back();
}

template<typename Item_type>
bool Vstack<Item_type>::empty() {
	return container.empty();
}

template<typename Item_type>
size_t Vstack<Item_type>::size() {
	return container.size();
}

template<typename Item_type>
int Vstack<Item_type>::average() {
	return total/container.size() ;
}

#endif