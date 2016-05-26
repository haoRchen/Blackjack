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
		chips = 10000;
		//cout << "player name:" << name << endl;
		//cout << "player chips:" << chips << endl;//testing for object creation
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
