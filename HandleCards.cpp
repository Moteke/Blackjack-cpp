#include "HandleCards.h"

std::vector<int> templateCards(52);

bool initialize52Cards()
{
	if(templateCards.size() < 52)
        return false;

    // initialize cards values [2 to 9]
    for (int i{ 0 }; i < 8; ++i) {
        templateCards[4 * i] = i + 2;
        templateCards[4 * i + 1] = i + 2;
        templateCards[4 * i + 2] = i + 2;
        templateCards[4 * i + 3] = i + 2;
    }

    // add (10, J, Q, K) 4 * 4 times value 10 to the templateCards

    for (int i{ 32 }; i < 48; ++i) {
        templateCards[i] = 10;
    }

    // lastly add four -1 values indicating aces
    for (int i{ 48 }; i < 52; ++i) {
        templateCards[i] = -1;
    }

    // CARDS DONE!
    return true;
}

/*
    Returns a proper card value.
    sumOfOtherCards is needed here to decide if an ace card should evaluate to 1 or 11    
*/
int getCardValue(int sumOfOtherCards)
{
    int value{ templateCards[randomCardsGenerator::getRandomCard()] };
    if (value == -1) {
        if (sumOfOtherCards < 11)
            value = 11; // 11 will not make the player loose
        else
            value = 1;
    }

    return value;
}

