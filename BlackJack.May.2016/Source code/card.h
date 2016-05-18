#ifndef BJ_CARD_H_
#define BJ_CARD_H_

namespace bj
{
	class card
	{
		int number; // card number
		char suit; //suits can be Spades(s), Hearts(h), Clubs(c), Diamonds(d)  
	public:
		card();//initializes the class card to a blank slate
		card(int,char);//initializes the card according to values being passed in 
		int getNumber() const;
		void setNumber(int);
		char getSuit() const;
		void setSuit(char*);
		void draw();//draw the shape of a playing card with a number and suit
	};
}

#endif