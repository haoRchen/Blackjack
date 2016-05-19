#ifndef BJ_BLACKJACK_H_
#define BJ_BLACKJACK_H_
#include "card.h"

#define MAX_DECK_SIZE 52

namespace bj
{
	class blackjack {
		int deck[MAX_DECK_SIZE];
		int top;
		card* card_[MAX_DECK_SIZE];//pointer array of card object
	public:
		blackjack();
		~blackjack();
		void shuffle();
		void push(int);
		int getdeck(int) const;
		card* pop();

	};




}

#endif
