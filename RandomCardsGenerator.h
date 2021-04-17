#pragma once

#include <ctime>
#include <functional>
#include <random>


namespace cardsGenerator {

    int getRandomCard();

	// forward declarations
	extern std::mt19937 generator;
	extern std::uniform_int_distribution<int> dist;
}