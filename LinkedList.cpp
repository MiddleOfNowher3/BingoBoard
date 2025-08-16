#include "LinkedList.h"

struct node
{
	KeyType data;
	node* next;
};


LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::~LinkedList()
{
	Clear();
}


bool LinkedList::IsFull() const
{
	return false;
}


bool LinkedList::IsEmpty() const
{
	return (head == nullptr);
}

node* LinkedList::Allocate()
{
	node* temp;
	try
	{//attempt to allocate a new node

		temp = new node; //gets a new node
		temp->next = nullptr;  //allows other function to put own data in
	}
	catch (bad_alloc&) //throws error if it can't allocate
	{//throws error if it can't
		throw OutOfMemoryException();
	}//end of catch

	return temp;
}



void LinkedList::Input(KeyType key)
{
	if (IsEmpty())
	{//when no elements
		head = Allocate();
		
	}//end of if
	else
	{
		node* temp = Allocate();
		temp->next = head;
		head = temp;
		
	}//end of else

	//for input to list
	head->data = key;

}//end of Input

void LinkedList::Delete()
{
	if (!IsEmpty())
	{

		if (head->next != nullptr)
		{ //when there is more than 1 element
			node* temp = head;
			head = head->next;
			delete temp;
			temp = nullptr;
		}
		else
		{//one element
			delete head;
			head = nullptr;
		}
	}//end of if(IsEmpty)

}//end of delete

void LinkedList::Clear()
{
	while (!IsEmpty())
	{
		Delete();
	}//end of while
}//end of Clear

bool LinkedList::Find(KeyType key)
{
	node* temp = head;
	while (temp != nullptr)
	{

		if (temp->data == key)
			return true;
		temp = temp->next;
	}

	return false;
}


KeyType LinkedList::RetAll()
{ //puts all of LinkedList into a string(used a typedef)
	KeyType retList = "";

	if (IsEmpty())
	{
		throw RetrieveOnEmptyException();
	}
	else
	{
		node* temp = head;



		while (temp != nullptr)
		{
			retList += temp->data;
			retList += "\n";
			temp = temp->next;
		}

	}//end of else


	return retList;
}