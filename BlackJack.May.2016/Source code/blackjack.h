#ifndef BJ_BLACKJACK_H_
#define BJ_BLACKJACK_H_

#define MAX_DECK_SIZE 52

namespace bj
{
	class blackjack {
		int deck[MAX_DECK_SIZE];
	public:
		blackjack();
		int getdeck(int) const;
		void shuffle();

	};




}

#endif
