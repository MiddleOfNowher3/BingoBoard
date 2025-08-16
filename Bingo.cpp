#include<iostream>
#include<cctype>
#include"BingoClass.h"
using namespace std;

void ClearScr();
int main()
{
	BingoClass Board;
	char charInput = 'Y';
	 
	do
	{

		ClearScr();

		do
		{
			cout << Board.GenSection() << endl;


			cout << "Is there a Bingo" << "\n" <<
				"Y for Yes, N for No" << endl;
			cin >> charInput;
			charInput = toupper(charInput);

			ClearScr();
		} while (charInput == 'N');


		cout << Board.OutputAll() << endl;

		cout << "Check For Bingo" << '\n' <<
			"Y for Yes, N for No" << endl;
		cin >> charInput;
		charInput = toupper(charInput);
	} while (charInput == 'N');


	Board.Bingo();
	return 0;
}

//clears screen
void ClearScr()
{
	//system("cls");

	#ifdef _WIN32
		system("cls");   
	#else
		system("clear"); 
	#endif
}