//Container.cpp
//Author: Andrew Choi
//Purpose: Implementation file for Container.h. Implements
//					the functions created in Container.h to use in the 
//				    main class. WIll be used in the recursive funtion
#include "Container.h"


using namespace std;

//Container: Constructor that creates the linked list
//Precondition: None
//Postcondition: Intitializes head of linked list, setting all private variables to 0
Container::Container()
{
	head = nullptr;
	tail = nullptr;
	counter = 0;
}

//Container: Copy constructor to copy input Container
//Precondition: Container (input) exists and there is sufficient memory
//Postcondition: A copy of the Container(input) is made
Container::Container(const Container& aList)
{
	counter = 0;
	head = nullptr;
	*this = aList;
}

//~Container: Destructer for Container class
//Precondition: Container exists 
//Postconsition: Deallocates the linked list for Container class
Container:: ~Container()
{
	Node* cur = head;
	while (head != nullptr)
	{
		head = head->next;
		delete cur;
		cur = head;
	}
}

//	operator=: Equal overload that sets obj to this class
//Precondition: Container obj exists 
//Postcondition: Deallocates current list and assigns input list to current lsit
Container & Container:: operator=(const Container& obj)
{
	if (this == &obj) return *this;

	Node* cur = head;
	while (head != nullptr)
	{
		head = head->next;
		delete cur;
		cur = head;
	}
	counter = obj.counter;

	if (obj.head == nullptr)
		head = nullptr;

	else
	{
		head = new Node;
		head->data = obj.head->data;
		tail = head;

		Node* newPtr = head;

		for (Node* origPointer = obj.head->next; origPointer != nullptr; origPointer = origPointer->next)
		{
			newPtr->next = new Node;
			newPtr = newPtr->next;
			newPtr->data = origPointer->data;
			tail = newPtr;
		}
		newPtr->next = nullptr;
	}
	
	return *this;
}

//addPixel: Adds a pixel to the end of the linked list
//Precondition: RGB values in pix is within bounds and column /width is within the image
//Postcondition: Adds a pixel to the end of the linked list returns true if added
bool Container::addPixel(pixelz pix)
{
   	Node* n = new Node;
	n->data = pix;
	n->next = nullptr;

	if (head == nullptr)
	{
		head = n;
		tail = n;
		counter++;
	}
	else
	{
		tail->next = n;
		tail = tail->next;
		counter++;
	}
	return true;
}

//size: Returns the dimension of the image
//Precondition: Dimensions must be non negative
//Postcondition: Return the width * dimension of image
int Container::size() const
{
	return counter;
}

//averageGreen: Retunrs an int of the avergage green of the container\
	//Precondition: Each color should be within bounds of 0-255
	//Postcondition: Returns the average of the green pixelz in the container
int Container::averageGreen()const
{

	int avgGreen = 0;
	Node* current = head;
	while (current != nullptr)
	{
		avgGreen += current->data.green;
		current = current->next;
	}
	return (avgGreen / size());
}

//averageRed: Retunrs an int of the avergage red of the container\
	//Precondition: Each color should be within bounds of 0-255
	//Postcondition: Returns the average of the red pixelz in the container
int Container::averageRed()const
{
	int avgRed = 0 ;
	Node* current = head;
	while (current != nullptr)
	{
		avgRed += current->data.red;
		current = current->next;
	}
	return (avgRed / size());
}

//averageBlue: Retunrs an int of the avergage blue of the container\
	//Precondition: Each color should be within bounds of 0-255
	//Postcondition: Returns the average of the blue pixelz in the container
int Container::averageBlue()const
{
	int avgBlue = 0;
	Node* current = head;
	while (current != nullptr)
	{
		avgBlue += current->data.blue;
		current = current->next;
	}
	return (avgBlue / size());
}


//merge: Merges the Container list object to calling object
//Precondition: Container other exists
//Postcondition: Adds the input Container to current calling object. Does not change 
//                          parameter.Returns true if list were merged
bool Container::merge(Container list2)
{
	if (list2.head == nullptr)
		return false;
	
	//If no data in current list call copy constructor and assignment operator
	if (head == nullptr || tail == nullptr)
	{
		Container copy(list2);
		*this = copy;
		return true;
	}

	tail->next  = list2.head;
	tail = tail->next;
	list2.head = list2.head->next;
	counter++;

	while (list2.head != nullptr)
	{
		tail->next = new Node;
		tail = tail->next;
		tail->data = list2.head->data;
		list2.head = list2.head->next;
		counter++;
	}
	tail->next = nullptr; 
	return true;
}

//Print: Prints out the data in the linked list
//Precondition: Linked lIst exists
//Postcondition: Prints out the RGB vaalus along with the row and column
void Container::print() 
{
	Node* cur = head;
	while (cur != nullptr)
	{
		cout << " Red: " << cur->data.red <<  " Green: " <<  cur->data.green << " Blue: "
			<< cur->data.blue << " Row: " << cur->data.row << " Column: " << cur -> data.column << endl;
		cur = cur->next;
	}

}

//Remove: Remvoes from the head of the linked list and returns the data
//Precondition: List exists
//Postcondition: Removes from the head of list and returns RGB values and row/column
Container::pixelz Container::remove()
{
	Container::pixelz  temp{};
	if (head != nullptr)
	{
		 temp = head->data;
		
		Node* junk = head;
		head = head->next;
		delete junk;
		junk = nullptr;
		counter--;
	}
	return temp;
}

//setAvgColor: Sets all the RGB values to the lists average
//Precondition: List exists
//Postcondition: Sets the RGB values to the lists average
void Container::setAvgColor()
{
	Node* cur = head;

	int avgRed = averageRed();
	int avgGreen = averageGreen();
	int avgBlue = averageBlue();

	while (cur != nullptr)
	{
		cur->data.red = avgRed;
		cur->data.green = avgGreen;
		cur->data.blue = avgBlue;

		cur = cur->next;
	}
}

//emptyList: Deletes all the data from the container
//Precoindition: The list exists
//Postcondition: deletes all the nodes from the list
	void Container::emptyList()
	{
			Node* cur = head;
			while (head != nullptr)
			{
				head = head->next;
				delete cur;
				cur = head;
			}
			counter = 0;
			head = nullptr;
			tail = nullptr;
	}
