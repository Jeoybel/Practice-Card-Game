#pragma once
#include <iostream>

using namespace std;

// Global constants to fine tune difficulty
const double EASYMULT = 0.8;
const double MEDMULT = 1.0;
const double HARDMULT = 1.2;
const int EASYNUMSWAPS = 2;
const int MEDNUMSWAPS = 3;
const int HARDNUMSWAPS = 4;
const int EASYPAUSE = 5;
const int MEDPAUSE = 4;
const int HARDPAUSE = 3;
const int EASYNUMCARDS = 3;
const int MEDNUMCARDS = 4;
const int HARDNUMCARDS = 5;

class Settings {
public:
	Settings();
	Settings(string);
	~Settings();

	string getDifficulty() const;
	double getMultiplier() const;
	int getNumSwaps() const;
	int getPauseLength() const;
	int getNumCards() const;

private:
	string difficulty;
	double multiplier;
	int numSwaps;
	int pauseLength;
	int numCards;
};

