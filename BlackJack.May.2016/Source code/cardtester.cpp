#include <iostream>
#include "card.h"

using namespace std;

int main()
{
	bj::card deck1(9);
	cout << "Card number: " << deck1.getNumber() << endl;
	cout << "suit: " << deck1.getSuit() << endl;
	bj::card deck2(24);
	cout << "Card number: " << deck2.getNumber() << endl;
	cout << "suit: " << deck2.getSuit() << endl;
	bj::card deck3(52);
	cout << "Card number: " << deck3.getNumber() << endl;
	cout << "suit: " << deck3.getSuit() << endl;
	//worked! 5/18/2016
	return 0;
}