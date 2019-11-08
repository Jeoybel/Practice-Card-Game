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
	displayCardsInPlay(true);	// display cards face up
	cout << "\nMemorize the cards!" << endl;
	wait(1.8);
	countdown(5);
	cout << "GO" << endl;
	wait(0.8);
	displayCardsInPlay(false);	// display cards face down
	wait(1);
	makeAllSwaps();
	cout << endl;
	decideCards();
	wait(1.5);
	displayCardsInPlay(true);	// display cards face up
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
	int cardPos{ (int)(rand() % allCards.size()) };
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
		cout << endl;
		countdown(pSettings->getPauseLength());
		displayCardsInPlay(false);
		if (i != pSettings->getNumSwaps() - 1) {
			wait(1);
		}
	}
}

/*
* Swap two random cards in play
*/
void CardGame::swapRandomCards() {
	int card1Pos = rand() % cardsInPlay.size();				// get random index from temporary vector
	int card2Pos = rand() % (cardsInPlay.size() - 1);		// get random index from temporary vector as if 1 card was taken from it
	if (card2Pos >= card1Pos) { card2Pos += 1; }			// correct card 2 position and ensure that card doesn't swap with itself
	swap(cardsInPlay[card1Pos], cardsInPlay[card2Pos]);		// swap those cards in cards in play
	displaySwaps(card1Pos, card2Pos);						// display which cards were swapped
}

/*
* Displays swaps given two card positions
*/
void CardGame::displaySwaps(int card1, int card2) {
	clearConsole();
	for (size_t i = 0; i < cardsInPlay.size(); i++) {
		string cardFace{ "" };
		(i == card1 || i == card2) ? cardFace = "[*]" : cardFace = "[ ]";
		cout << "|  ";
		cout << cardFace;
		cout << "\t|";
	}
	cout << endl;
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
			cout << "Correct! +" << scoreboard.scorePoints(true) << " points!" << endl;
		} else {
			cout << "Incorrect! -" << scoreboard.scorePoints(false) << " points." << endl;
		}
		cout << endl;
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
* Display cards in play face up, or face down depending on parameter
*/
void CardGame::displayCardsInPlay(bool shown) const {
	clearConsole();
	for (auto it = cardsInPlay.begin(); it != cardsInPlay.end(); ++it) {
		string cardFace{ "" };
		shown ? cardFace = *it : cardFace = "[ ]";
		cout << "|  ";
		cout << cardFace;
		cout << "\t|";
	}
	cout << endl;
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

