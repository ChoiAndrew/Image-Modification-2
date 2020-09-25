//Container.h
//Author: Andrew Choi
//Purpose: Header file for Container.cpp. Contains all the
//         methods in the public section of the class and
//         the local variable in the private section
#ifndef Container_H
#define Container_H
#include <iostream>  

class Container
{
public:
	//Struct to represent a pixel. Contains rgb value and location
	struct pixelz
	{
		int red;
		int green;
		int blue;
		int row;
		int column;
	};

private:
	//Node struct that contains the pointer to next and the data
	struct Node
	{
		Node* next;
		pixelz  data;
	};
	//Private variables to point to the head and table of the list

	Node* head;
	Node* tail;
	int counter;

public:
	//Container: Constructor that creates the linked list
	//Precondition: None
	//Postcondition: Intitializes head of linked list, setting all private variables to 0
	Container();
	/*
		1. Constructs an empty list
	*/

	//Container: Copy constructor to copy input Container
	//Precondition: Container (input) exists and there is sufficient memory
	//Postcondition: A copy of the Container(input) is made
	Container(const Container& input);
	/*
	  1. Checks to see if obj contains any nodes, if not do nothing
	  2. Make two nodes (current) and (temp)
	  3. else traverse obj list using while loop (current.next !=null)
	  4. copy data to current container by using the add funtion
	*/

	//	operator=: Equal overload that sets obj to this class
   //Precondition: Container obj exists 
   //Postcondition: Deallocates current list and assigns input list to current lsit
	Container &operator = (const Container& obj);
	/*
		 2. Deallocate current Container
		 3. Initialize new Node (current) to point to obj'shead
		 2. Traverse obj using while loop and add data to current list
		 3. Set current to next link
		 4. Outside the loop set head equal to current
		 Return *this
	*/


	//~Container: Destructer for Container class
	//Precondition: Container exists 
	//Postconsition: Deallocates the linked list for Container class
	~Container();
	/*
		1. Make two nodes. One(current) to point to head and one(next) that points to next
		2. Traverse the list using a while loop as long as current.next != null
		3. next -> current.next
		4. delete current node
		5. set current to next
	*/

	//addPixel: Adds a pixel to the end of the linked list
	//Precondition: RGB values in pix is within bounds and column /width is within the image
	//Postcondition: Adds a pixel to the end of the linked list returns true if added
	bool addPixel(pixelz pix);
	/*
		1. Make a new node and set the new nodes data to pix
		2. Check to see if current list has a head
		2. add the node to the end of the list by using tail
		3. Have the tail pointer point to the new node
		4. Return true if pix was added

	*/
	//merge: Merges the Container list object to calling object
	//Precondition: Container other exists
	//Postcondition: Adds the input Container to current calling object. Does not change 
	//                          parameter.Returns true if list were merged
	bool merge(Container other);
	/*
		1. Check to see if current list has any node(nullptr)  if not  return false
		2. Check to see if input other is empty  if not return false
		3. Else make new node for current to point to head of other.
			 have while loop to traverse other
		4. add the current to the tail.next until current.next == nullptr
		5. deallocate the input list  (other)
		6. return true at the end once list are merged
	*/

	//size: Returns the dimension of the image
	//Precondition: Dimensions must be non negative
	//Postcondition: Return the width * dimension of image
	int size()const;
	/*
		1. Initialize a counter to one
		2. Make a node(current)
		3. Traverse the list using a while loop and increment until current.next == nullptr
		4. return the count outside the loop
	*/

	//averageGreen: Retunrs an int of the avergage green of the container\
	//Precondition: Each color should be within bounds of 0-255
	//Postcondition: Returns the average of the green pixelz in the container
	int  averageGreen() const;
	/*
			1. intiailize int temp equal to 0
			2. Make a new node(current) to point to head
			3. Traverse the list using a while loop where current -> next is not nullptr
			4. add all the green values of the data to temp
			5.  outside the loop, divide temp by size() and return that value
	*/

	//averageRed: Retunrs an int of the avergage red of the container\
	//Precondition: Each color should be within bounds of 0-255
	//Postcondition: Returns the average of the red pixelz in the container
	int averageRed() const;
	/*
			1. intiailize int temp equal to 0
			2. Make a new node(current) to point to head
			3. Traverse the list using a while loop where current -> next is not nullptr
			4. add all the red values of the data to temp
			5.  outside the loop, divide temp by size() and return that value
	*/

	//averageBlue: Retunrs an int of the avergage blue of the container\
	//Precondition: Each color should be within bounds of 0-255
	//Postcondition: Returns the average of the blue pixelz in the container
	int  averageBlue() const;
	/*
			1. intiailize int temp equal to 0
			2. Make a new node(current) to point to head
			3. Traverse the list using a while loop where current -> next is not nullptr
			4. add all the blue values of the data to temp
			5.  outside the loop, divide temp by size() and return that value
	*/

	//Print: Prints out the data in the linked list
	//Precondition: Linked lIst exists
	//Postcondition: Prints out the RGB vaalus along with the row and column
	void print();

	//Remove: Remvoes from the head of the linked list and returns the data
	//Precondition: List exists
	//Postcondition: Removes from the head of list and returns RGB values and row/column
	pixelz remove();

	//setAvgColor: Sets all the RGB values to the lists average
	//Precondition: List exists
	//Postcondition: Sets the RGB values to the lists average
	void setAvgColor();

	//emptyList: Deletes all the data from the container
	//Precoindition: The list exists
	//Postcondition: deletes all the nodes from the list
	void emptyList();
};

#endif
