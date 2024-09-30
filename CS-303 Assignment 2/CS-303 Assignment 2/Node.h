// Node.h
#ifndef NODE_H_
#define NODE_H_

template<typename Item_type>
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


#endif
