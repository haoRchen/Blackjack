#include <iostream>
#include "blackjack.h"

using namespace std;

int main()
{
	bj::blackjack game1;
	//before shuffle
	/*for (int i = 0; i < MAX_DECK_SIZE; i++)
	{
		cout << game1.getdeck(i) << " ";
	}*/

	
	game1.shuffle();
	//after shuffle
	for (int i = 0; i < MAX_DECK_SIZE; i++)
	{
		cout << game1.getdeck(i) << " ";
	}

	return 0;
}