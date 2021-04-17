#include "BlackjackIO.h"
#include "Decision.h"
#include "HandleCards.h"
#include "MyUtils.h"
#include "Player.h"

#include <iostream>
#include <numeric>
#include <vector>

int main()
{
	using namespace std;

	initialize52Cards();

	Player player{ "Player" };
	Player croupier{ "Croupier" };

	// get 2 cards for the player and 1 for the croupier
	player.cards.emplace_back(getCardValue(player.sum));
	player.cards.emplace_back(getCardValue(player.sum));
	croupier.cards.emplace_back(getCardValue(croupier.sum));

	bool stop{ false };

	// 1. show player's cards
	blackjackIO::outputCards(player);
	// 2. show croupier's card
	blackjackIO::outputCards(croupier);
	// 3. ask player for decisions (if sum < 21): until stand is chosen or bust happens

	if (player.sum == 21)
	{
		std::cout << "BLACKJACK!\n";
	}
	else {
		auto decision = blackjackIO::askForADecision();

		// just some extra formatting
		//std::cout << '\n';

		while (decision == Decision::hit) {
			player.cards.emplace_back(getCardValue(player.sum));
			blackjackIO::outputCards(player);
			myUtils::sleep(500);
			if (player.sum >= 21)
				break;
			decision = blackjackIO::askForADecision();

			// just some extra formatting
			//std::cout << '\n';
		}
	}

	// bust is immediate loose
	if (player.sum > 21) {
		std::cout << "Sorry, you lost :(";
		return 0;
	}
	else if (player.sum == 21)
		std::cout << "BLACKJACK!\n";

	// 4. get cards for croupier until he has sum >= 17
	while (croupier.sum < 17) {
		std::cout << "Croupier gets a card...\n";
		myUtils::sleep(500);
		croupier.cards.emplace_back(getCardValue(croupier.sum));
		blackjackIO::outputCards(croupier);
		myUtils::sleep(500);
	}


	// 5. decide on who wins
	// 
	// if croupier went bust or has lower sum then player wins
	if (croupier.sum > 21 || player.sum > croupier.sum)
		std::cout << "YOU WON!!!";
	else if (player.sum == croupier.sum)
		std::cout << "It's a draw!";
	else
		std::cout << "You lost :(";

	return 0;
}