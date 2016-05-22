#include <iostream>
#include <time.h> //time
#include <stdlib.h> //srand/rand
#include <stdio.h> //sscanf
#include "blackjack.h"
#include "player.h"

using namespace std;

namespace bj {
	blackjack::blackjack()
	{
		//initialize the deck of cards 1-52
		for (int i = 0; i < MAX_DECK_SIZE; i++)
		{
			deck[i] = i+1;
		}
		//initialize all 52 card pointers to null
		for (int i = 0; i < MAX_DECK_SIZE; i++)
		{
			card_[i] = nullptr;
		}
		for (int i = 0; i < MAX_HAND_SIZE; i++)
		{
			house[i] = nullptr;
		}
		for (int i = 0; i < MAX_HAND_SIZE; i++)
		{
			humanPlayer[i] = nullptr;
		}
		player_ = nullptr;
		//tinialize top position of stack of cards
		top = -1;
	}
	blackjack::~blackjack()
	{	
		delete[] card_;
		delete[] house;
		delete[] humanPlayer;
		delete[] player_;
	}
	//for testing purposes
	int blackjack::getdeck(int i) const
	{
		return deck[i];
	}

	void blackjack::shuffle()//fisher-yate shuffle
	{
		int i = MAX_DECK_SIZE, index, temp;
		srand(time(NULL));
		/*
		For every different seed value used in a call to srand,
		the pseudo-random number generator can be expected to 
		generate a different succession of results in the 
		subsequent calls to rand.
		*/
		while (--i > 0)//note that index 0 won't be created as a result. if i == 0, integer division by zero exception!
		{
			index = rand() % i; //generate random index to be swapped
			temp = deck[index];// storing the value of randomly generated index position
			push(deck[index]); //send card value 1-52 for creation of card object, then pushed into deck array. 
			deck[index] = deck[i];//swap last index with whatever random index that was generated
			deck[i] = temp;//-assigning the swapped index value with the last in the array
			

		}
		cout << "deck shuffled!" << endl;//testing for occurance
	}
	//pushing cards into array of object pointer
	void blackjack::push(int cardnumber)
	{
		if (top == MAX_DECK_SIZE - 1)
		{
			cout << "Card stack is full!" << endl;
		}
		else
		{
			top += 1;//first position will be index 0!
			card_[top] = new card(cardnumber);
			//cout <<*card_[top] << endl; //testing for proper storing of card values
		}
	}
	//drawing a card from the top of the deck
	card* blackjack::pop()
	{
		card* tempcard = nullptr;
		if (top == -1)
		{
			cout << "the deck is empty!" << endl;
		}
		else
		{
			tempcard = card_[top];
			top -= 1;
		}
		return tempcard;
	}
	
	//check if player has more than 0$
	bool blackjack::playerHasMoney()
	{
		cout << "checking player money" << endl;//testing for proper access/value
		return player_->getChips() >= 0;
	}
	//oversight for player bet
	bool blackjack::checkPlayerBet(int amount)
	{
		cout << "checking player bet" << endl;//testing for proper access/value
		return amount <= player_->getChips();
	}
	
	//main menu
	int blackjack::menu()
	{
		int selection;
		cout << "BlackJack / 21!" << endl;
		cout << "1- New Game" << endl;
		cout << "2- Continue" << endl;
		cout << "3- Rules" << endl;
		cout << "0- Exit" << endl;
		cout << "> ";
		cin >> selection;
		cout << endl;
		cin.ignore(1000, '\n');
		return selection >= 0 && selection <= 3 ? selection : -1;
	}
	//check if the deck is empty
	bool blackjack::deckIsEmpty()
	{
		return top <= 10;
	}
	//check if cards in hand equates to 21
	int blackjack::handValue(int cardsInHand, card* hand)
	{
		int sum = 0, convertedValue;
		char value[6];
		for(int counter = 0; counter < cardsInHand; counter++)
		{
			strcpy(value, hand[counter].getNumber());
			value[5] = '\0';
			if(value == "Ace")
			{
				if(sum + 11 > 21)
				{
					sum += 1;
				}
			}
			else if( value == "Jack" || value == "Queen" || value == "King")
			{
				sum += 10;
			}
			else
			{
				sscanf(value, "%d", &convertedValue);
				sum += convertedValue;
			}
		}
		cout << "hand value checked" << endl;//testing function call
		return sum;
	}
	//reveal hands
	void blackjack::showHands(int noOfHouseCard, card* theHouse, int noOfPlayerCard, card* thePlayer, bool firstDeal)
	{
		int counter;
		cout << "House's hand: " << endl;
		if (firstDeal)
		{
			cout << theHouse[1];
		}
		else
		{
			for (counter = 0; counter < noOfHouseCard; counter++)
			{
				cout << theHouse[counter];
			}
		}
		cout << "Player's Hand: " << endl;
		for (counter = 0; counter < noOfHouseCard; counter++)
		{
			cout << thePlayer[counter];
		}
	}
	
	//in game player options
	int blackjack::inGameMenu()
	{
		int selection;
		cout << "1- Stay" << endl;
		cout << "2- Hit" << endl;
		cout << "0- Exit" << endl;
		cout << "> ";
		cin >> selection;
		cout << endl;
		cin.ignore(1000, '\n');
		return selection >= 0 && selection <= 2 ? selection : -1;
	}
	//running the program
	int blackjack::run()
	{
		int option = 1;
		while (option != 0)
		{
			option = menu();//receives the user selected option

			switch (option)
			{
				case 0:
				{
					cout << "See you next time!" << endl;

				}
				break;
				case 1://new game, 
				{
					char name[100];
					int betAmount, counter, playerCardNum = 0, houseCardNum = 0, inGameOption = 1, initialDeal = 2;
					bool playerWin, tie, roundEnd;
					cout << "Welcome, please enter your name: " << endl;
					cin >> name;
					player_ = new player(name);//new player creation with name and chips
					shuffle();
					while (playerHasMoney() && inGameOption != 0)
					{
						roundEnd = false;
						//must test
						if(deckIsEmpty())
						{
							shuffle();
						}
						do{
						cout << "Enter the amount you wish to bet: ";//stuck in constant loop>>>??
						cin >> betAmount;
						} while (!checkPlayerBet(betAmount));//while bet amount is invalid, re-enter amount. 
					
						for (counter = 0; counter < initialDeal; counter++)// 0, then 1.
						{
							house[counter] = pop();//pop returns a pointer to the top card, change to address??
							humanPlayer[counter] = pop();
							houseCardNum++;
							playerCardNum++;
						}
					 
						showHands(houseCardNum, *house, playerCardNum, *humanPlayer, true);//initial deal
						while (!roundEnd)//handValue(playerCardNum, *humanPlayer) != 21 && handValue(playerCardNum, *humanPlayer) < 21 &&  taken out
						{//player menu
							inGameOption = inGameMenu();
							switch (inGameOption)
							{
								case 1:
								{
									showHands(houseCardNum, *house, playerCardNum, *humanPlayer, false);
									while (handValue(houseCardNum, *house) < 17)
									{
										house[counter] = pop();
										cout << *house[counter];
										counter++;
										houseCardNum++;
									}
									if (handValue(houseCardNum, *house) > 21)
									{
										playerWin = false;
										roundEnd = true;
									}
									else
									{
										if (handValue(playerCardNum, *humanPlayer) == handValue(houseCardNum, *house))
										{
											tie = true;
											roundEnd = true;
										}
										else
										{
											playerWin = true; //handValue(playerCardNum, *humanPlayer) > handValue(houseCardNum, *house)
											roundEnd = true;
										}
									}
								}
								break;
								case 2:
								{
									humanPlayer[counter] = pop();
									cout << *humanPlayer[counter];
									counter++;
									playerCardNum++;
									if (handValue(playerCardNum, *humanPlayer) > 21)
									{
										roundEnd = true;
										playerWin = false;
										cout << "Bust!" << endl;
									}

								}
								break;
								case 0:
								{
									cout << "Goodbye!" << endl;
								}
								break;
								default:
								{
									cout << "invalid selection" << endl;
								}
							}
						}
						if (playerWin)// make if into a while loop?
						{
							//win round
							cout << "Win round!" << endl;
							player_->setChips(player_->getChips() + (betAmount * 2));//win double the bet
						}
						else if (tie)
						{
							cout << "Tie" << endl;
						}
						else
						{
							cout << "Lost round" << endl;
							player_->setChips(player_->getChips() - betAmount);
						}
						
					
					}

				}
				break;
				case 2:
				{
					cout << "load saved game" << endl;
				}
				break;
				case 3:
				{
					cout << "rules" << endl;
				}
				default:
				{
					cout << "===Invalid Selection, try again.===" << endl;
				}

			}
		}
		return 0;
	}

}
