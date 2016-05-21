#ifndef BJ_PLAYER_H_
#define BJ_PLAYER_H_
#include "card.h"

#define MAX_PLAYER_NAME 100
#define MAX_PLAYER_HAND 10

namespace bj
{
	class player
	{
		char name[MAX_PLAYER_NAME+1];
		int chips;
		card* hand[MAX_PLAYER_HAND];
	public:
		player();
		player(const char*);
		void setChips(int);
	};

}

#endif