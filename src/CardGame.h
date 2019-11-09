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
	void decideCards();								// player decides cards
	void resetCards();								// reset deck of cards and cards in play
	void initAllCards();							// set cards in deck
	void displayScore() const;						// display total score
	void printAllCards(const string& cardState) const;					// print all cards
	void printCard(const int& cardPos, const string& cardState) const;	// print a single card

private:
	vector<string> allCards;						// deck of cards
	vector<string> cardsInPlay;						// cards in play
	shared_ptr<Settings> pSettings;					// settings
	Scoreboard scoreboard;							// scoreboard
	int swapPos1;
	int swapPos2;
};

