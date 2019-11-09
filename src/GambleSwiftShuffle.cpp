#pragma once
#include <iostream>
#include "Utility.h"
#include "CardGame.h"

using namespace std;

int main() {
	string input{ "" };

	cout << "Welcome to my card game!\n" << endl;

	cout << "Instructions" << endl;
	cout << "============" << endl;
	cout << "You will be asked to remember the positions of several cards." << endl;
	cout << "When all of the cards are flipped over several swaps will be made represented by [*]." << endl;
	cout << "After all swaps are made recall as many cards as you can to score points." << endl;
	cout << "There will be a total of three rounds. Good luck!\n" << endl;

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
		cout << "Enter 'q' to quit, otherwise enter anything to continue!" << endl;
		cin >> input;
		cin.clear();
		cin.ignore(32767, '\n');
		input = stringToLower(input);
		clearConsole();
	}
}
