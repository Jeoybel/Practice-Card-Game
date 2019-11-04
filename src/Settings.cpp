#pragma once
#include "Settings.h"

Settings::Settings() :Settings("medium") {}

Settings::Settings(string difficulty) : difficulty(difficulty) {
	if (difficulty == "easy") {
		this->multiplier = EASYMULT;
		this->numSwaps = EASYNUMSWAPS;
		this->pauseLength = EASYPAUSE;
		this->numCards = EASYNUMCARDS;
	} else if (difficulty == "hard") {
		this->multiplier = HARDMULT;
		this->numSwaps = HARDNUMSWAPS;
		this->pauseLength = HARDPAUSE;
		this->numCards = HARDNUMCARDS;
	} else {
		this->multiplier = MEDMULT;
		this->numSwaps = MEDNUMSWAPS;
		this->pauseLength = MEDPAUSE;
		this->numCards = MEDNUMCARDS;
	}
}

Settings::~Settings() {}

string Settings::getDifficulty() const {
	return difficulty;
}

double Settings::getMultiplier() const {
	return multiplier;
}

int Settings::getNumSwaps() const {
	return numSwaps;
}

int Settings::getPauseLength() const {
	return pauseLength;
}

int Settings::getNumCards() const {
	return numCards;
}
