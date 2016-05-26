#include <iostream>
#include "blackjack.h"

using namespace std;

int main()
{
	bj::blackjack game1("blackjacksave.txt");
	return game1.run();
}