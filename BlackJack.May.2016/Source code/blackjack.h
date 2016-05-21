#ifndef BJ_BLACKJACK_H_
#define BJ_BLACKJACK_H_
#include "card.h"
#include "player.h"

#define MAX_DECK_SIZE 52
#define MAX_HAND_SIZE 10

namespace bj
{
	class blackjack {
		int deck[MAX_DECK_SIZE];
		int top;
		Player player_;
		card* card_[MAX_DECK_SIZE];//pointer array of card object/the stack
		card* house[MAX_HAND_SIZE];//house's hand
		card* humanPlayer[MAX_HAND_SIZE]; //player's hand
		void shuffle();
		void push(int);
		int getdeck(int) const;
		card* pop();//draw
		int menu();
		int inGameMenu();
		bool playerHasMoney();
		bool checkPlayerBet(int);
		bool deckIsEmpty();
		bool isTwentyOne(int, card*);
		
	public:
		blackjack();
		~blackjack();
		int run();


	};




}

#endif
