#include "RandomCardsGenerator.h"

namespace randomCardsGenerator {

	std::mt19937 generator(static_cast<std::mt19937::result_type>(time(nullptr)));
	std::uniform_int_distribution<int> dist(0, 51);

	// returns a number in range [0...51]
	int getRandomCard()
	{
		return dist(generator);
	}
}
