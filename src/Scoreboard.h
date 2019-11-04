#pragma once
#include <memory>
#include "Settings.h"

class Scoreboard {
public:
	Scoreboard();
	Scoreboard(shared_ptr<Settings>);
	~Scoreboard();

	int getScore() const;

	int scorePoints(bool correctAnswer);

private:
	int score;
	shared_ptr<Settings> pSettings;
};

