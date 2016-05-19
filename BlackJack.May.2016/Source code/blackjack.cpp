#include <iostream>
#include <time.h> //time
#include <stdlib.h> //srand/rand
#include "blackjack.h"

using namespace std;

namespace bj {
	blackjack::blackjack()
	{
		//initialize the deck of cards 1-52
		for (int i = 0; i < MAX_DECK_SIZE; i++)
		{
			deck[i] = i+1;
		}
		//initialize all 52 card pointers to null
		for (int i = 0; i < MAX_DECK_SIZE; i++)
		{
			card_[i] = nullptr;
		}
		//tinialize top position of stack of cards
		top = -1;
	}
	blackjack::~blackjack()
	{	
		delete [] card_;
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
		while (--i > 0)//note that index 0 won't be created as a result. if i == 0, integer division by zero exception!
		{
			index = rand() % i; //generate random index to be swapped
			temp = deck[index];// storing the value of randomly generated index position
			push(deck[index]); //send card value 1-52 for creation of card object, then pushed into deck array. 
			deck[index] = deck[i];//swap last index with whatever random index that was generated
			deck[i] = temp;//-assigning the swapped index value with the last in the array
			

		}
	}
	//pushing cards into array of object pointer
	void blackjack::push(int cardnumber)
	{
		if (top == MAX_DECK_SIZE - 1)
		{
			cout << "Card stack is full!" << endl;
		}
		else
		{
			top += 1;//first position will be index 0!
			card_[top] = new card(cardnumber);
			cout <<*card_[top] << endl; //testing for proper storing of card values
		}
	}
	card* blackjack::pop()
	{
		card* tempcard = nullptr;
		if (top == -1)
		{
			cout << "the deck is empty!" << endl;
		}
		else
		{
			tempcard = card_[top];
			top -= 1;
		}
		return tempcard;
	}

}