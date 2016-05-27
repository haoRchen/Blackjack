#include <iostream>
#include <time.h> //time
#include <stdlib.h> //srand/rand
#include <stdio.h> //sscanf
#include <cstdlib> //system pause
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
		resetHand();
		resetPlayer();
		//tinialize top position of stack of cards
		top = -1;
	}

	blackjack::~blackjack()
	{	
		for (int i = 0; i < MAX_HAND_SIZE; i++)
		{
			delete house[i];
		}
		for (int i = 0; i < MAX_HAND_SIZE; i++)
		{
			delete humanPlayer[i];
		}
		/*for (int i = 0; i < MAX_HAND_SIZE; i++)
		{
			delete splitHand[i];
		}*/
		resetHand();
	}

	//for testing purposes
	/*int blackjack::getdeck(int i) const
	{
		return deck[i];
	}*/

	void blackjack::resetPlayer()
	{
		player_ = nullptr;
	}

	void blackjack::resetHand()
	{

		int i;
		for (i = 0; i < MAX_HAND_SIZE; i++)
		{
			house[i] = nullptr;
		}
		for (i = 0; i < MAX_HAND_SIZE; i++)
		{
			humanPlayer[i] = nullptr;
		}
		/*for (i = 0; i < MAX_HAND_SIZE; i++)
		{
			splitHand[i] = nullptr;
		} */
	}

	void blackjack::resetDeck()
	{
		//initialize all 52 card pointers to null
		for (int i = 0; i < MAX_DECK_SIZE; i++)
		{
			delete card_[i];
			card_[i] = nullptr;
		}
		top = -1;
	}

	void blackjack::shuffle()//fisher-yate shuffle
	{
		int i = MAX_DECK_SIZE, index, temp;
		resetDeck();
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
		cout << "Deck shuffled!" << endl;//testing for occurance
	}

	//pushing cards into array of object pointer
	void blackjack::push(int cardnumber)
	{
		if (top == MAX_DECK_SIZE - 1) // if the array of object is full
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

	//draw a card from the top of the deck
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
	bool blackjack::playerHasMoney() const
	{
		//cout << "checking player money" << endl;//testing for proper access/value
		return player_->getChips() > 0;
	}
	//oversight for player bet
	bool blackjack::checkPlayerBet(int amount) const
	{
		//cout << "checking player bet" << endl;//testing for proper access/value
		return amount <= player_->getChips() && amount > 0;
	}
	
	//check if the deck is empty
	bool blackjack::deckIsEmpty() const
	{
		return top <= 10;
	}

	//check if cards in hand equates to 21
	int blackjack::handValue(int cardsInHand, card* hand[]) const
	{
		int sum = 0, convertedValue;
		bool aceInHand = false;
		char value[6];
		for(int counter = 0; counter < cardsInHand; counter++)
		{
			strcpy(value, hand[counter]->getNumber());
			value[5] = '\0';
			if(value[0] == 'A')
			{
				sum += 11;
				aceInHand = true;
			}
			else if(value[0] == 'J' || value[0] == 'Q' || value[0] == 'K')
			{
				sum += 10;
			}
			else
			{
				sscanf(value, "%d", &convertedValue);
				sum += convertedValue;
			}
		}

		if (aceInHand && sum > 21)
		{
			sum -= 10;//making Ace == 1
		}
		//cout << "hand value checked: " << sum << endl;//testing function call and sum value

		return sum;
	}

	//reveal hands
	void blackjack::showHands(int noOfHouseCard, card* theHouse[], int noOfPlayerCard, card* thePlayer[], bool firstDeal) const 
	{
		int counter;
		cout << "House's hand: " << endl;
		if (firstDeal)
		{
			cout << *theHouse[1];
		}
		else
		{
			for (counter = 0; counter < noOfHouseCard; counter++)
			{
				cout << *theHouse[counter];
			}
		}
		cout << "Player's Hand: " << endl;
		for (counter = 0; counter < noOfPlayerCard; counter++)
		{
			cout << *thePlayer[counter];
		}
	}

	//pause
	void blackjack::pause()
	{
		cin.clear();
		cout << "Press Enter to continue..." << endl;
		cin.ignore(2000, '\n');

	}

	//adds white spaces
	void blackjack::clearScreen()
	{
		for (int counter = 0; counter < 50; counter++)
		{
			cout << endl;
		}
	}

	//main menu
	int blackjack::menu()
	{
		cout << "########################" << endl;
		cout << "#                      #" << endl;
		cout << "#   BlackJack / 21!    #" << endl;
		cout << "#   ===============    #" << endl;
		cout << "#   | 1- Play     |    #" << endl;
		cout << "#   | 2- Rules    |    #" << endl;
		cout << "#   | 0- Exit     |    #" << endl;
		cout << "#   |_____________|    #" << endl;
		cout << "#                      #" << endl;
		cout << "########################" << endl;
		cout << "> ";
		int selection = inGameMenuPrompt();
		return selection >= 0 && selection <= 2 ? selection : -1;
	}

	//display the rules of the game
	void blackjack::rules()
	{
		cout << "_______________________________________________________________________________________________________" << endl;
		cout << "|                                                                                                      |" << endl;
		cout << "|  How to play BlackJack/21                                                                            |" << endl;
		cout << "|                                                                                                      |" << endl;
		cout << "|======================================================================================================|" << endl;
		cout << "|                                                                                                      |" << endl;
		cout << "|  Objective:                                                                                          |" << endl;
		cout << "|     Beat the dealer by attempting to get close to 21, without going over!                            |" << endl;
		cout << "|                                                                                                      |" << endl;
		cout << "|  Card Value:                                                                                         |" << endl;
		cout << "|      Face cards = 10 | Ace = 1 or 11 | Other cards = face value                                      |" << endl;
		cout << "|                                                                                                      |" << endl;
		cout << "|  Betting:                                                                                            |" << endl;
		cout << "|      The player can bet no more than his or her total chips                                          |" << endl;
		cout << "|                                                                                                      |" << endl;
		cout << "|  The Deck:                                                                                           |" << endl;
		cout << "|      Will be reshuffled when only 20% of cards remain                                                |" << endl;
		cout << "|                                                                                                      |" << endl;
		cout << "|  The Deal:                                                                                           |" << endl;
		cout << "|      Cards will be dealt alternating between the dealer and the player.                              |" << endl;
		cout << "|      The dealer's first card will remain hidden, while all other cards dealt will be revealed        |" << endl;
		cout << "|                                                                                                      |" << endl;
		cout << "|  Naturals:                                                                                           |" << endl;
		cout << "|      If the player's first two cards equate to 21, it is a natural/blackjack.                        |" << endl;
		cout << "|      If the player has a natural and the dealer does not, the player wins the round automatically    |" << endl;
		cout << "|      Vice-versa for the dealer                                                                       |" << endl;
		cout << "|                                                                                                      |" << endl;
		cout << "|  Player options:                                                                                     |" << endl;
		cout << "|      1. Stand - Compare hand value with the dealer                                                   |" << endl;
		cout << "|      2. Hit - Receives an additional card from the deck.                                             |" << endl;
		cout << "|           If player's hand value is over 21, then it is a bust.                                      |" << endl;
		cout << "|                                                                                                      |" << endl;
		cout << "|  Dealer's Play:                                                                                      |" << endl;
		cout << "|      Once the player stands, the dealer must continue to draw until hand value is 17 or over.        |" << endl;
		cout << "|      The player wins if dealer's hand value is over 21 (Bust)                                        |" << endl;
		cout << "|                                                                                                      |" << endl;
		cout << "|  Doubling Down:                                                                                      |" << endl;
		cout << "|      This option will be presented only when the hand value of the player is 9, 10 or 11 after       |" << endl;
		cout << "|          the initial deal. The player can choose to place a bet equal to the original amount,        |" << endl;
		cout << "|          and will receive one card from the dealer.                                                  |" << endl;
		cout << "|______________________________________________________________________________________________________|" << endl;


	}

	//in game player options
	int blackjack::inGameMenu()
	{
		cout << "___________" << endl;
		cout << "|         |" << endl;
		cout << "| Options |" << endl;
		cout << "|---------|" << endl;
		cout << "| 1- Stay |" << endl;
		cout << "| 2- Hit  |" << endl;
		cout << "| 0- Exit |" << endl;
		cout << "|_________|" << endl;
		cout << "> ";
		int selection = inGameMenuPrompt();
		
		return selection >= 0 && selection <= 2 ? selection : -1;
	}

	int blackjack::inGameMenuPrompt()
	{
		bool validInput = false;
		int selection;
		do
		{
			cin >> selection;
			if (cin.good())
			{
				validInput = true;
			}
			else
			{
				cin.clear();
				cin.ignore(2000, '\n');
				cout << "--Invalid input, please re-enter!--" << endl;
				cout << "> ";
			}
		} while (!validInput);
		return selection;
	}

	int blackjack::doubleDown()
	{
		cout << "Would you like to double down?" << endl;
		cout << "1 - Yes" << endl;
		cout << "2 - No" << endl;
		cout << "> ";
		int selection = inGameMenuPrompt();
		return selection >= 1 && selection <= 2 ? selection : -1;
	}

	/*int blackjack::split()
	{
		cout << "Would you like to split?" << endl;
		cout << "1 - Yes" << endl;
		cout << "2 - No" << endl;
		cout << "> ";
		int selection = inGameMenuPrompt();
		return selection >= 1 && selection <= 2 ? selection : -1;
	}  */

	//running the program
	int blackjack::run()
	{
		int option = 1;
		while (option != 0)
		{
			system("PAUSE");
			clearScreen();
			option = menu();
			switch (option)
			{
				//exiting program
				case 0:
				{
					cout << "--See you next time!--" << endl;
					pause();

				}
				break;
				//new game
				case 1: 
				{
					char name[1000];
					pause();
					int betAmount, doubleDownTrigger = 1, inGameOption = 1, initialDeal = 2;
					bool playerWin, tie, roundEnd;
					cout << "Welcome, please enter your name: ";
					cin.getline(name, 1000, '\n');
					name[999] = '\0';
					player_ = new player(name);//new player creation with name and chips
					shuffle();
					while (playerHasMoney() && inGameOption != 0)
					{
						bool roundEnd = false, playerWin = false, tie = false;
						int counter = 0, playerCardNum = 0, houseCardNum = 0, playerHandValue = 0;
						resetHand();
						if(deckIsEmpty())
						{
							shuffle();
						}
						do{
						
							bool validInput = false;
							cout << "Chips Amount: " << player_->getChips() << endl;
							cout << "Enter the amount you wish to bet for this round: ";//stuck in constant loop>>>??
							cin >> betAmount;
							if (cin.good()) //check to see if only integers are entered
							{
								validInput = true;
							}
							else
							{
								cin.clear();
								cin.ignore(2000, '\n');
								cout << "--Invalid input, please re-enter!--" << endl;
								cout << "> ";
							}
						} while (!checkPlayerBet(betAmount));//while bet amount is invalid, re-enter amount. 
					
						for (counter = 0; counter < initialDeal; counter++)// 0, then 1.
						{
							house[houseCardNum] = pop();//pop returns a pointer to the top card, change to address??
							humanPlayer[playerCardNum] = pop();
							houseCardNum++;
							playerCardNum++;
						}
						clearScreen();
						playerHandValue = handValue(playerCardNum, humanPlayer);
						showHands(houseCardNum, house, playerCardNum, humanPlayer, true);//initial deal
						//natural
						if (playerHandValue == 21 && handValue(houseCardNum, house) != 21)
						{
							roundEnd = true;
							playerWin = true;
						}
						else if (playerHandValue == 21 && handValue(houseCardNum, house) == 21)
						{
							roundEnd = true;
							tie = true;
						}
						else if (handValue(houseCardNum, house) == 21)
						{
							roundEnd = true;
							playerWin = false;
							cout << "--House has 21!--" << endl;
						}
						if (playerHandValue == 9 || playerHandValue == 10 || playerHandValue == 11)//trigger double down option
						{

							doubleDownTrigger = doubleDown();
							if (doubleDownTrigger == 1 && player_->getChips() >= betAmount)
							{
								humanPlayer[playerCardNum] = pop();
								playerCardNum++;
								betAmount *= 2;
								clearScreen();
								showHands(houseCardNum, house, playerCardNum, humanPlayer, false);
								if (handValue(playerCardNum, humanPlayer) == handValue(houseCardNum, house))
								{
									tie = true;
									roundEnd = true;
								}
								else
								{
									playerWin = handValue(playerCardNum, humanPlayer) > handValue(houseCardNum, house);
									roundEnd = true;
								}
							}
						
						}
						
						/*if (humanPlayer[0] == humanPlayer[1])
						{
								
							splitTrigger = split();//check whether player wants to split
							if (splitTrigger == 1)
							{
								splitHand[0] = humanPlayer[1];//assign address?
								delete humanPlayer[1];
								splitHand[1] = pop();//second card for the other hand
								//no tracker yet
								humanPlayer[1] = pop();

							}

						} */
							
						while (!roundEnd && inGameOption != 0)
						{//player menu
							inGameOption = inGameMenu();

							switch (inGameOption)
							{
								case 0:
								{
									cout << "--Goodbye!--" << endl;
									delete player_;
								}
								break;
								case 1:
								{
									while (handValue(houseCardNum, house) < 17)
									{
										clearScreen();
										showHands(houseCardNum, house, playerCardNum, humanPlayer, false);
										house[houseCardNum] = pop();
										cout << *house[houseCardNum];//another clear screen with show card
										houseCardNum++;

									}
									if (handValue(houseCardNum, house) > 21)
									{
										clearScreen();
										showHands(houseCardNum, house, playerCardNum, humanPlayer, false);
										playerWin = true;
										cout << "--House Bust!--" << endl;
										roundEnd = true;
									}
									else
									{
										clearScreen();
										showHands(houseCardNum, house, playerCardNum, humanPlayer, false);
										if (handValue(playerCardNum, humanPlayer) == handValue(houseCardNum, house))
										{
											tie = true;
											roundEnd = true;
										}
										else
										{
											playerWin = handValue(playerCardNum, humanPlayer) > handValue(houseCardNum, house);
											roundEnd = true;
										}
									}
								}
								break;
								case 2:
								{
									clearScreen();
									showHands(houseCardNum, house, playerCardNum, humanPlayer, true);//doesn't reveal house's other card
									humanPlayer[playerCardNum] = pop();
									cout << *humanPlayer[playerCardNum];
									playerCardNum++;
									if (handValue(playerCardNum, humanPlayer) > 21)
									{
										roundEnd = true;
										playerWin = false;
										cout << "--Player Bust!--" << endl;
									}

								}
								break;
								default:
								{
									cout << "====invalid selection====" << endl;
								}
							}
						}
						
						if (playerWin)
						{
							//win round
							cout << "--Win round!--" << endl;
							player_->setChips(player_->getChips() + betAmount);//win double the bet

						}
						else if (tie)
						{
							cout << "--Tie--" << endl;

						}
						else if(!playerWin && inGameOption!= 0)
						{
							cout << "--Lost round--" << endl;
							player_->setChips(player_->getChips() - betAmount);

						}
						
					
					}

				}
				break;
				//display rules to player
				case 2:
				{
					rules();

				}
				break;
				//invalid menu option
				default:
				{
					cout << "===Invalid Selection, try again.===" << endl;
				}

			}
		}
		return 0;
	}

}
