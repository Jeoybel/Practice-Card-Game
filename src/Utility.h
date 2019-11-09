#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

std::string stringToLower(std::string rawString) {
	for (auto it = rawString.begin(); it != rawString.end(); ++it) {
		*it = tolower(*it);
	}
	return rawString;
}

int findIndex(const std::vector<std::string>& vec, std::string findString) {
	int index{ -1 };
	int tempIndex{ 0 };
	if (!vec.empty()) {
		for (auto it = vec.begin(); it != vec.end(); ++it) {
			if (*it == findString) {
				index = tempIndex;
				break;
			}
			++tempIndex;
		}
	}
	return index;
}

void countdown(int start) {
	for (size_t i = start; i > 0; i--) {
		std::cout << "(" << i << " s) ";
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	std::cout << std::endl;
}

inline void wait(int waitTime) {
	std::this_thread::sleep_for(std::chrono::seconds(waitTime));
}

inline void clearConsole() {
	system("CLS");
}