#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<cstdlib>
#include<new>
#include<string>
#include"Exceptions.h"

using namespace std;

struct node;
typedef string KeyType;

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void Input(KeyType key);
	bool Find(KeyType key);
	void Delete();
	void Clear();
	bool IsEmpty() const;
	bool IsFull() const;
	KeyType RetAll(); //puts all of LinkedList into a string(used a typedef)

protected:
	node* Allocate();

private:
	node* head;
};

#endif