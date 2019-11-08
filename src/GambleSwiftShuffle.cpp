#pragma once
#include <iostream>
#include "Utility.h"
#include "CardGame.h"

using namespace std;

int main() {
	string input{ "" };

	while (input != "q") {													// Type 'q' to exit game loop
		while (input != "easy" && input != "medium" && input != "hard") {	// Type difficulty to set game
			cout << "(easy), (medium), (hard)" << endl;
			cout << "Enter difficulty: ";
			cin >> input;
			cin.clear();
			cin.ignore(32767, '\n');
			input = stringToLower(input);
		}
		CardGame cardGame(input);
		cout << "Type 'q' to quit, otherwise continue!" << endl;
		cin >> input;
		cin.clear();
		cin.ignore(32767, '\n');
		input = stringToLower(input);
		clearConsole();
	}
}
