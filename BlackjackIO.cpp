#include "BlackjackIO.h"

#include <iostream>
#include <limits>

namespace blackjackIO {
	void outputCards(Player& p)
	{
		std::cout << p.name << "'s cards (sum: " << p.sum <<"): ";
		for (auto card : p.cards) {
			std::cout << card << " ";
		}
		std::cout << '\n';
	}

	Decision askForADecision()
	{
		int decision{ -1 };
		bool fail{ false };

		// validate input
		while (decision < 0 || decision > static_cast<int>(Decision::max_decision) || fail) {
			fail = false;

			std::cout << "Do you want to hit (1) or stand (2)? ";
			std::cin >> decision;

			if (std::cin.fail()) {
				std::cin.clear();
				fail = true;
			}

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}
	
		return static_cast<Decision>(decision);
	}
}