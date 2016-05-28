#ifndef BJ_PLAYER_H_
#define BJ_PLAYER_H_
#include "card.h"

#define MAX_PLAYER_NAME 100

namespace bj
{
	class player
	{
		char name[MAX_PLAYER_NAME+1];
		int chips;
	public:
		player();
		player(const char*);
		void setChips(int);
		int getChips() const;
	};

}

#endif
