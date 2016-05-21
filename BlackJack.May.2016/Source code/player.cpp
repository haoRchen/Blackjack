#include <iostream>
#include "player.h"

using namespace  std;

namespace bj
{
	player::player()
	{
		name[0] = '\0';
		chips = 0;
	}

	player::player(const char* playername)
	{
		strcpy(name, playername);
		name[MAX_PLAYER_NAME] = '\0';
		chips = 1000;
	}

	void player::setChips(int c)
	{
		chips = c;
	}
	int player::getChips() const 
	{
		return chips; 
	}

}
