#pragma once
#include "CardGame.h"

CardGame::CardGame() :CardGame::CardGame("medium") {}

CardGame::CardGame(string difficulty)
	: pSettings(make_shared<Settings>(difficulty)), scoreboard(pSettings) {
	srand(time(NULL));	// seed rand() with time to eliminate repetitive swaps
	runGame();			// run game once
}

CardGame::~CardGame() {}

void CardGame::runGame() {
	clearConsole();
	cout << "Starting game! (" << pSettings->getDifficulty() << ")" << endl;
	wait(1.5);
	initAllCards();
	setupRound();
	printAllCards("shown");
	cout << "\nMemorize the cards!" << endl;
	wait(1.8);
	countdown(5);
	cout << "GO" << endl;
	wait(0.8);
	printAllCards("hidden");
	wait(1);
	makeAllSwaps();
	cout << endl;
	decideCards();
	wait(1.5);
	printAllCards("shown");
	cout << endl;
	displayScore();
}

/*
* Push cards into play one by one by picking random cards from deck
*/
void CardGame::setupRound() {
	for (size_t i = 0; i < pSettings->getNumCards(); i++) {
		cardsInPlay.push_back(pickRandomCard());
	}
}

/*
* Pick random card from deck, remove it from deck, return it
*/
string CardGame::pickRandomCard() {
	int cardPos = rand() % allCards.size();
	string cardPicked{ allCards[cardPos] };
	allCards.erase(allCards.begin() + cardPos);
	return cardPicked;
}

/*
* Make all swaps, number of total swaps depends on difficulty
*/
void CardGame::makeAllSwaps() {
	for (size_t i = 0; i < pSettings->getNumSwaps(); i++) {
		swapRandomCards();
		printAllCards("swapped");
		cout << endl;
		countdown(pSettings->getPauseLength());
		printAllCards("hidden");
		if (i != pSettings->getNumSwaps() - 1) {
			wait(1);
		}
	}
}

/*
* Swap two random cards in play
*/
void CardGame::swapRandomCards() {
	swapPos1 = rand() % cardsInPlay.size();					// get random index from temporary vector
	swapPos2 = rand() % (cardsInPlay.size() - 1);			// get random index from temporary vector as if 1 card was taken from it
	if (swapPos2 >= swapPos1) swapPos2 += 1;				// correct card 2 position and ensure that card doesn't swap with itself
	swap(cardsInPlay[swapPos1], cardsInPlay[swapPos2]);		// swap these cards in cards in play
}

/*
* User decides what the cards are for points
*/
void CardGame::decideCards() {
	string input{ "" };
	for (size_t i = 0; i < pSettings->getNumCards(); i++) {
		cout << "What is card #" << (i + 1) << "?: ";
		cin >> input;
		cin.clear();
		cin.ignore(32767, '\n');
		if (stringToLower(input) == stringToLower(cardsInPlay[i])) {
			cout << "Correct! +" << scoreboard.scorePoints(true) << " points! " << endl;
		} else {
			cout << "Incorrect!" << endl;
		}
	}
}

/*
* Clear deck and cards in play and reinitialize deck to default value
*/
void CardGame::resetCards() {
	cardsInPlay.clear();
	allCards.clear();
	initAllCards();
}

/*
* Set deck of cards. More or less cards can be added
*/
void CardGame::initAllCards() {
	allCards = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Q", "K", "J" };
}

/*
* Display total score
*/
void CardGame::displayScore() const {
	cout << "Total Score: " << scoreboard.getScore() << endl;
}

/*
* Print all cards
*/
void CardGame::printAllCards(const string& cardState) const {
	clearConsole();
	cout << endl;
	for (size_t i = 0; i < cardsInPlay.size(); i++) {
		if (cardState == "shown") {
			printCard(i, "shown");
		} else if (cardState == "hidden") {
			printCard(i, "hidden");
		} else if (cardState == "swapped") {
			if (i == swapPos1 || i == swapPos2) {
				printCard(i, "swapped");
			} else {
				printCard(i, "hidden");
			}
		}
	}
	cout << endl;
}

/*
* Print one card
*/
void CardGame::printCard(const int& cardPos, const string& cardState) const {
	cout << "|  ";
	if (cardState == "shown") cout << cardsInPlay[cardPos];
	else if (cardState == "swapped") cout << "[*]";
	else if (cardState == "hidden") cout << "[ ]";
	cout << "\t|";
}
