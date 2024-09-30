//Alejandro Torres
//COMPSCI 303 Assignment 1

#include <iostream>
#include "Linkedlist.h"
#include "Stack.h"
#include "Node.h"


int main() {

	try {
		Linked<std::string> something;
		
		std::cout << "Q1 Build a single Linked List class." << std::endl << std::endl;

		std::cout << "1. push_front" << std::endl;
		something.push_front("Sam");
		something.push_front("George");
		something.push_front("Wah");
		something.displayList();
		std::cout << std::endl;

		std::cout << "2. push_back" << std::endl;
		something.push_back("Tony");
		something.push_back("Sony");
		something.push_back("Bonny");
		something.displayList();
		std::cout << std::endl;

		std::cout << "3. pop_front" << std::endl;
		something.pop_front();
		something.displayList();
		std::cout << std::endl;

		std::cout << "4. pop_back" << std::endl;
		something.pop_back();
		something.displayList();
		std::cout << std::endl;

		std::cout << "5. front, back" << std::endl;
		something.front();
		something.back();
		std::cout << std::endl;

		std::cout << "6. empty" << std::endl;
		std::cout << "Is this list is empty? (true: 1, false: 0): " << something.empty() << std::endl;
		std::cout << std::endl;

		std::cout << "7. insert (Example index 1)" << std::endl;
		something.insert( 1 ,"something");
		something.displayList();
		std::cout << std::endl;

		std::cout << "8. remove (Example index 2)" << std::endl;
		something.remove(2);
		something.displayList();
		std::cout << std::endl;

		std::cout << "9. find (Example Sony) and return its index." << std::endl;
		std::cout << "This word is at index: " << something.find("Sony") << std::endl;
		something.displayList();
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Q2 for the implementation of a stack of integers using a vector." << std::endl;
		
		// 1. Create a stack object.
		Vstack<int> numberHole;

		std::cout << "2. Check the stack is empty or not." << std::endl;
		std::cout << "Checking to see if stack is empty? (true: 1, false: 0): " << numberHole.empty() << std::endl;
		std::cout << std::endl;

		std::cout << "3. Insert some integer values onto the stack." << std::endl;
		numberHole.push(4);
		numberHole.push(5);
		numberHole.push(7);
		numberHole.push(10);
		std::cout << "Values inserted are 4, 5, 7, 10 So the top should be :" << numberHole.top() << std::endl;
		std::cout << std::endl;

		std::cout << "4. Remove an element from the stack." << std::endl;
		numberHole.pop();
		std::cout << "Value 10 has been removed So the top should be :" << numberHole.top() << std::endl;
		std::cout << std::endl;

		std::cout << "5. Find the Top of the stack." << std::endl;
		std::cout << "Top: " << numberHole.top() << std::endl;
		std::cout << std::endl;

		std::cout << "6. Find average value of the stack elements." << std::endl;
		std::cout << "The average of the stack is: " << numberHole.average() << std::endl;




	}
	catch (const std::out_of_range& ex) {
		std::cout << "\nERROR: " << ex.what() << std::endl;
	}
	catch (const std::invalid_argument& ex) {
		std::cout << "\nERROR: " << ex.what() << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << "\nERROR: " << ex.what() << std::endl;
	}
	// Catches any arguement out of the scope of errors.
	catch (...) {
		std::cout << "Something happend with the code." << std::endl;
		return 0;
	}


	return 0;
}

//sizeof()