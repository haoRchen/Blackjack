#include <iostream>
#include "blackjack.h"

using namespace std;

int main()
{
	bj::blackjack game1;
	//before shuffle
	for (int i = 0; i < MAX_DECK_SIZE; i++)
	{
		cout << game1.getdeck(i) << " ";
	}
	cout << endl;

	game1.shuffle();
	//after shuffle
	for (int i = 0; i < MAX_DECK_SIZE; i++)
	{
		cout << game1.getdeck(i) << " "; // the value was being printed, not index
	}
	cout << endl;
	//printing out the cards drawn(popped)
	cout << endl << *(game1.pop()) << endl;
	
	cout << endl << *(game1.pop()) << endl;

	//working 5/19/2016
	return 0;
}