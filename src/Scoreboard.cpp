#include "Scoreboard.h"

Scoreboard::Scoreboard() :score(0), pSettings{ make_shared<Settings>("medium") } {}

Scoreboard::Scoreboard(shared_ptr<Settings> pSettings) : score(0), pSettings{ pSettings } {}

Scoreboard::~Scoreboard() {

}

int Scoreboard::getScore() const {
	return score;
}

int Scoreboard::scorePoints(bool correctAnswer) {
	int previousScore = getScore();
	correctAnswer ? score += 10 * pSettings->getMultiplier() : score -= 10 * pSettings->getMultiplier();	// add or subtract points if answered correctly or not. Points have a multiplier for difficulty
	return abs(score - previousScore);
}
