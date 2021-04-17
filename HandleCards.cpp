#include "HandleCards.h"

bool initialize52Cards(std::vector<int>& container)
{
	if(container.size() < 52)
		return false;

    // initialize cards values [2 to 9]
    for (int i{ 0 }; i < 8; ++i) {
        container[4 * i] = i + 2;
        container[4 * i + 1] = i + 2;
        container[4 * i + 2] = i + 2;
        container[4 * i + 3] = i + 2;
    }

    // add (10, J, Q, K) 4 * 4 times value 10 to the container

    for (int i{ 32 }; i < 48; ++i) {
        container[i] = 10;
    }

    // lastly add four -1 values indicating aces
    for (int i{ 48 }; i < 52; ++i) {
        container[i] = -1;
    }

    // CARDS DONE!
    return true;
}