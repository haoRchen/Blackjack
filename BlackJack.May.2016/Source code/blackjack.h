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
		char filename_[256];
		int top;
		player* player_;
		card* card_[MAX_DECK_SIZE];//pointer array of card object/the stack
		card* house[MAX_HAND_SIZE];//house's hand
		card* humanPlayer[MAX_HAND_SIZE]; //player's hand
		void resetHand();//delete previously assigned addresses to card*
		void resetDeck();//delete previously assigned address and set to nullptr
		void resetPlayer();//delete previously assigned player stat
		void shuffle();
		void push(int);
		int getdeck(int) const;
		card* pop();//draw
		int menu();
		int inGameMenu();
		int doubleDown();
		bool playerHasMoney();
		bool checkPlayerBet(int);
		bool deckIsEmpty();
		int handValue(int, card* []);
		void showHands(int, card* [], int, card* [], bool);
		void clearScreen();//adds 50 \n to clear screen
		void rules();//displays rules
		void pause();//flushes input
		
		
	public:
		blackjack(const char*);
		~blackjack();
		int run();


	};




}

#endif
