#include <iostream>
#include <cstring>
#include "card.h"

namespace bj
{
	card::card()
	{
		number = 0;
		suit = '\0';
	}

	card::card(int n, char s)
	{
		setNumber(n);
		setSuit(s);
	}

	int card::getNumber()const
	{
		return number;
	}
	
	void card::setNumber(int n)
	{
		number = n;
	}

	char card::getSuit() const
	{
		return suit;

	}

	void card::setSuit(char* s)
	{
		strcpy(suit, s);
	}

	void card::draw()
	{
		std::cout << "----------" << std::endl;
		std::cout << "|        |" << std::endl;
		std::cout << "|        |" << std::endl;
		std::cout << "|        |" << std::endl;
		std::cout << "|        |" << std::endl;
		std::cout << "|        |" << std::endl;
		std::cout << "----------" << std::endl;
	}


}