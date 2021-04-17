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

	player.cards.emplace_back(getCardValue(player.sum));
	player.cards.emplace_back(getCardValue(player.sum));
	croupier.cards.emplace_back(getCardValue(croupier.sum));

	bool stop{ false };

	blackjackIO::outputCards(player);
	blackjackIO::outputCards(croupier);

	if (player.sum == 21)
	{
		std::cout << "BLACKJACK!\n";
	}
	else {
		auto decision = blackjackIO::askForADecision();


		while (decision == Decision::hit) {
			player.cards.emplace_back(getCardValue(player.sum));
			blackjackIO::outputCards(player);
			myUtils::sleep(500);
			if (player.sum >= 21)
				break;
			decision = blackjackIO::askForADecision();

		}
	}

	if (player.sum > 21) {
		std::cout << "Sorry, you lost :(";
		return 0;
	}
	else if (player.sum == 21)
		std::cout << "BLACKJACK!\n";

	while (croupier.sum < 17) {
		std::cout << "Croupier gets a card...\n";
		myUtils::sleep(500);
		croupier.cards.emplace_back(getCardValue(croupier.sum));
		blackjackIO::outputCards(croupier);
		myUtils::sleep(500);
	}


	if (croupier.sum > 21 || player.sum > croupier.sum)
		std::cout << "YOU WON!!!";
	else if (player.sum == croupier.sum)
		std::cout << "It's a draw!";
	else
		std::cout << "You lost :(";

	return 0;
}