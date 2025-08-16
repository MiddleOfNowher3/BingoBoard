#include "BingoClass.h"



BingoClass::BingoClass()
{
	list = new LinkedList;
	srand(time(0));
	ct = 0;
}

void BingoClass::Bingo()
{
	delete list;
}

KeyType BingoClass::GenSection()
{
	KeyType letterSel = "00";
	if (ct < MAX_NUM)
	{

		short letterNum; //used for what letter for selection
		short bingoNum = 0;
		ct++;
		bool noRepeat = true;

		do
		{

			letterNum = rand() % 5;
			switch (letterNum)
			{
			case 0: letterSel = "B"; bingoNum = rand() % 15 + 1; break;
			case 1: letterSel = "I"; bingoNum = rand() % 15 + 16; break;
			case 2: letterSel = "N"; bingoNum = rand() % 15 + 31; break;
			case 3: letterSel = "G"; bingoNum = rand() % 15 + 46; break;
			case 4: letterSel = "O"; bingoNum = rand() % 15 + 61; break;
			};

			letterSel += to_string(bingoNum);


		} while (list->Find(letterSel));

		list->Input(letterSel);
	}
	return letterSel;

}//end of GenSelction


KeyType BingoClass::OutputAll()
{
	return list->RetAll();
}