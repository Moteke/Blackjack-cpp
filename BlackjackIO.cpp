#include "BlackjackIO.h"

namespace blackjackIO {
	void outputCards(Player& p)
	{
		std::cout << p.name << "'s cards (sum: " << p.sum <<"): ";
		for (auto card : p.cards) {
			std::cout << card << " ";
		}
		std::cout << '\n';
	}
}