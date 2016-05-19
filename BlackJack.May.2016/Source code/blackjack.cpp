#include <iostream>
#include <time.h> //time
#include <stdlib.h> //srand/rand
#include "blackjack.h"

using namespace std;

namespace bj {
	//initialize the deck of cards 1-52
	blackjack::blackjack()
	{
		for (int i = 0; i < MAX_DECK_SIZE; i++)
		{
			deck[i] = i+1;
		}
	}
	//for testing purposes
	int blackjack::getdeck(int i) const
	{
		return deck[i];
	}

	void blackjack::shuffle()//fisher-yate shuffle
	{
		int i = MAX_DECK_SIZE, index, temp;
		srand(time(NULL));
		/*
		For every different seed value used in a call to srand,
		the pseudo-random number generator can be expected to 
		generate a different succession of results in the 
		subsequent calls to rand.
		*/
		while (--i > 0)
		{
			index = rand() % i;
			temp = deck[index];
			deck[index] = deck[i];
			deck[i] = temp;
		}
	}

}