#include <iostream>
#include "card.h"

using namespace std;

int main()
{
	bj::card deck1(12);
	cout << "Card number: " << deck1.getNumber() << endl;
	cout << "suit: " << deck1.getSuit() << endl;
	bj::card deck2(11);
	cout << "Card number: " << deck2.getNumber() << endl;
	cout << "suit: " << deck2.getSuit() << endl;
	bj::card deck3(13);
	cout << "Card number: " << deck3.getNumber() << endl;
	cout << "suit: " << deck3.getSuit() << endl;

	cout << deck1;
	//worked! 5/18/2016
	return 0;
}