#ifndef BJ_BLACKJACK_H_
#define BJ_BLACKJACK_H_
#include "card.h"
#include "player.h"

#define MAX_DECK_SIZE 52
#define MAX_HAND_SIZE 10

namespace bj
{
	class blackjack {
		int deck[MAX_DECK_SIZE];//an array for shuffling
		int top;
		player* player_;
		card* pop();//draw
		card* card_[MAX_DECK_SIZE];//pointer array of card object/the stack
		card* house[MAX_HAND_SIZE];//house's hand
		card* humanPlayer[MAX_HAND_SIZE]; //player's hand
		void shuffle();//shuffle the deck
		void push(int);//for shuffling, add shuffled card objects into deck
		//card* splitHand[MAX_HAND_SIZE];//Player's other hand if split is triggered
		void resetHand();//delete previously assigned addresses to card*
		void resetDeck();//delete previously assigned address and set to nullptr
		void resetPlayer();//delete previously assigned player stat
		//int getdeck(int) const;//for testing 
		int menu();//main menu
		int inGameMenu();
		int doubleDown();//double down option
		int inGameMenuPrompt(); //prompt player for option until valid input is given
		//int split(); //future feature
		bool playerHasMoney() const;//check if the player has money to play
		bool checkPlayerBet(int) const;//check if the bet is not more than what the player has
		bool deckIsEmpty() const;//check if the deck is down to the last 10 cards
		int handValue(int, card* []) const;//return the combined value of cards in hand
		void showHands(int, card* [], int, card* [], bool) const;//display cards in hand, with option to hide the house's first card
		void clearScreen();//adds 50 \n to clear screen
		void rules();//displays rules
		void pause();//flushes input
		
		
	public:
		blackjack();
		~blackjack();
		int run();//runs the program


	};




}

#endif
