#include <iostream>
#include "player.h"

using namespace  std;

namespace bj
{
	player::player()
	{
		name[0] = '\0';
		chips = 0;
		for (int i = 0; i < MAX_PLAYER_HAND; i++)
		{
			hand[i] = nullptr;
		}
	}

	player::player(const char* playername)
	{
		strcpy(name, playername);
		name[MAX_PLAYER_NAME] = '\0';
		chips = 1000;
		for (int i = 0; i < MAX_PLAYER_HAND; i++)
		{
			hand[i] = nullptr;
		}
	}

	void player::setChips(int c)
	{
		chips = c;
	}

}