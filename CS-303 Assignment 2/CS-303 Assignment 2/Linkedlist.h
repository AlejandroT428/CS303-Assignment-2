// Linkedlist.h
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "Namespace.h"




template<typename Item_type>

class Linked {
private:
	
struct Node {
	//Data Fields
	// The data
	Item_type data;
	// The pointer to the next node.
	Node* next;

	// Constructor
	/** Creates a new Node that points to another Node.
	* @param data_item the data stored
	* @param next_ptr Pointer to the Node that is pointed to by the new Node.
	*/
	Node(const Item_type& data_item, Node* next_ptr = NULL) :
		data(data_item), next(next_ptr) {}
};
	Node* head;
	Node* tail;
	size_t num_items;
	
public:
	// Constructor
	Linked();

	void displayList();
	void push_front(const Item_type& item);
	void push_back(const Item_type& item);
	void pop_front();
	void pop_back();
	void front(); 
	void back(); 
	bool empty();
	void insert(size_t index, const Item_type& item); //Insert item at position index (starting at 0). Insert at the end if index is beyond the end of the list.
	bool remove(size_t index); // Remove the item at position index. Return true if successful; return false if index is beyond the end of the list.
	size_t find(const Item_type& item); // Return the position of the first occurrence of item if it is found. Return the size of the list if it is not found.

};

template<typename Item_type>
Linked<Item_type>::Linked() {
	head = nullptr;
	tail = nullptr;
	num_items = 0;
}

template<typename Item_type>
void Linked<Item_type>::front() {
	std::cout << head->data << " " << head << std::endl;
}

template<typename Item_type>
void Linked<Item_type>::back() {
	std::cout << tail->data << " " << tail << std::endl;
}

template<typename Item_type>
void Linked<Item_type>::displayList() {
	Node* current = head;
	while (current) {
	std::cout << current->data << std::endl;
		current = current->next;
	}

//	std::cout << head->data << head->next->data << std::endl;
}

template<typename Item_type>
void Linked<Item_type>::push_front(const Item_type& item) {
	if (head == nullptr) {
		Node* newNode = new Node(item, tail);
		head = newNode;
	}
	else if (tail == nullptr) {
		Node* tempNode = new Node(head->data, nullptr); // creates new tail
		Node* newNode = new Node(item, tempNode); // creates new head	
		tail = tempNode;
		head = newNode;
	}
	else {
		head = new Node(item, head);
	}

	++num_items;
}

template<typename Item_type>
void Linked<Item_type>::push_back(const Item_type& item) {
	if (head == nullptr) {
		Node* newNode = new Node(item, tail);
		head = newNode;
	}
	else if (tail == nullptr) {
		Node* newNode = new Node(item, nullptr);
		tail = newNode;
	}
	else {
		Node* newNode = new Node(item, nullptr);
		tail->next = newNode;
		tail = newNode;
	}

	++num_items;
}

template<typename Item_type>
void Linked<Item_type>::pop_front() {
	//check for special cases
	if (head == NULL || head->next == NULL) {
		throw std::exception("Cannot delete the node");
	}

	Node* temp = head;
	head = head->next;
	delete temp;
	--num_items;
	return;
}

template<typename Item_type>
void Linked<Item_type>::pop_back() {
	//check for special cases
	if (head == NULL || tail == NULL) {
		throw std::exception("Cannot delete the node");
	}

	Node* current_Node = head;
	while (current_Node != NULL) {
		if (current_Node->next->next == NULL) {
			Node* temp = tail;
			tail = current_Node;
			tail->next = NULL; // If you get rid of a tail, make sure its pointing to NULL and not a string of errors.
			delete temp;
			--num_items;
			return;
		}
		current_Node = current_Node->next;
	}
}

template<typename Item_type>
bool Linked<Item_type>::empty() {
	if (head == NULL && tail == NULL) {
		return true;
	}
	else {
		return false;
	}
}

template<typename Item_type>
void Linked<Item_type>::insert(size_t index, const Item_type& item) {
	// checks if the index is beyond the list.
	if (index > num_items) {
		push_back(item);
	} 
	else if (index == 0) {
		push_front(item);
	}
	else {

		Node* current_Node = head; 
		for (int i = 1; i < num_items; i++) {
			if (i == index) {
				current_Node->next = new Node(item, current_Node->next);
				break;
			}
			current_Node = current_Node->next;
		}
	}

	++num_items;
	return;
}

template<typename Item_type>
bool Linked<Item_type>::remove(size_t index) {
	// checks if the index is beyond the list.
	if (index > num_items) {
		return false;
	}
	else if (index == 0) { // Checks if its the head
		pop_front();
	}
	else {

		Node* current_Node = head;
		for (int i = 1; i < num_items; i++) {
			if (i == index) {
				Node* temp = current_Node->next;
				current_Node->next = current_Node->next->next;
				delete temp;
				break;
			}
			current_Node = current_Node->next;
		}
	}

	--num_items;
	return true;
}

// Return the position of the first occurrence of item if it is found. Return the size of the list if it is not found.
template<typename Item_type>
size_t Linked<Item_type>::find(const Item_type& item) {
	
	if (empty()) {
		throw std::exception("List is empty!");
	}

	Node* current_Node = head;
	for (int i = 0; i < num_items; i++) {
		if (item == current_Node->data) {
			return i;
		}
		current_Node = current_Node->next;
	}

	return num_items;
}

#endif