#ifndef BINGOCLASS_H
#define BINGOCLASS_H

#include "LinkedList.h" //use to store previous choices

#include <ctime>

using namespace std;


const unsigned short MAX_NUM = 75;


class BingoClass
{
	public:
		BingoClass(); //default constructor
		KeyType GenSection(); //generates next item on Board
		void Bingo();
		KeyType OutputAll();

	private:
		LinkedList* list;
		KeyType select;
		unsigned short ct;
		
};

#endif