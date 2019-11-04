#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "Settings.h"
#include "Scoreboard.h"
#include "Utility.h"

using namespace std;

class CardGame {
public:
	CardGame();
	CardGame(string difficulty);
	~CardGame();

	void runGame();									// run single game
	void setupRound();								// setup cards in play
	string pickRandomCard();						// select single random card from deck(allCards)
	void makeAllSwaps();							// make all random swaps. Number of swaps depending on difficulty
	void swapRandomCards();							// swap 2 random cards
	void displaySwaps(int card1Pos, int card2Pos);	// display swapped cards
	void decideCards();								// player decides cards
	void resetCards();								// reset deck of cards and cards in play
	void displayCardsInPlay(bool shown) const;		// display cards in play. Parameter of true shows cards face up.
	void initAllCards();							// set cards in deck
	void displayScore() const;						// display total score

private:
	vector<string> allCards;						// deck of cards
	vector<string> cardsInPlay;						// cards in play
	shared_ptr<Settings> pSettings;					// settings
	Scoreboard scoreboard;							// scoreboard
};

