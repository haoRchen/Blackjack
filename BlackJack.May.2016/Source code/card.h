#ifndef BJ_CARD_H_
#define BJ_CARD_H_

#define MAX_NUMBER_SIZE 5

namespace bj
{
	class card
	{
		char number[MAX_NUMBER_SIZE +1]; // card number
		char suit; //suits can be Spades(s), Hearts(h), Clubs(c), Diamonds(d)  
	public:
		card();//initializes the class card to a blank slate
		card(int);//initializes the card according to values being passed in 
		const char* getNumber() const;
		void setNumber(int); // set card number based on 1-13 
		const char getSuit() const;
		void setSuit(char);
		//void draw();//draw the shape of a playing card with a number and suit
	};
	std::ostream& operator<<(std::ostream&, const card&);
}

#endif