#include <iostream>
#include <cstring>
#include "card.h"

using namespace std;

namespace bj
{
	card::card()
	{
		number[0] = '\0';
		suit = '\0';
	}

	card::card(int value)
	{
		//cout << value << endl;//testing randomized value
		if (value >= 1 && value <= 13)
		{
			setSuit('H');
			setNumber(value);
			
		}
		else if (value >= 14 && value <= 26)
		{
			setSuit('D');
			setNumber((value - 13));
		}
		else if (value >= 27 && value <= 39)
		{
			setSuit('C');
			setNumber((value - 26));
		}
		else if (value >= 40 && value <= 52)
		{
			setSuit('S');
			setNumber((value - 39));
		}



	}

	const char* card::getNumber()const
	{
		return number;
	}
	
	void card::setNumber(int value)
	{	
		if (value > 1 && value < 11)
		{
			//number[0] = value;
			itoa(value, number, 10);
			//convert an int value to string(created already), with 10 being decimal base)
			//number[MAX_NUMBER_SIZE] = '\0';
			//do not need to manually terminate as string is an object that contains a null terminator
		}
		else if (value == 1)
		{
			strcpy(number, "Ace");
			number[MAX_NUMBER_SIZE] = '\0';
		}
		else if (value == 11)
		{
			strcpy(number, "Jack");
			number[MAX_NUMBER_SIZE] = '\0';
		}
		else if (value == 12)
		{
			strcpy(number, "Queen");
			number[MAX_NUMBER_SIZE] = '\0';
		}
		else if (value == 13)
		{
			strcpy(number, "King");
			number[MAX_NUMBER_SIZE] = '\0';
		}

	}

	const char card::getSuit() const
	{
		return suit;

	}

	void card::setSuit(char s)
	{
		suit = s;
	}

	std::ostream& operator<<(std::ostream& os, const card& c)
	{
		os << "Card: " << c.getNumber() 
			<< " Suit: " << c.getSuit() << endl;
		return os;
	}

}