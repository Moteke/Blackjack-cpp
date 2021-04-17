#pragma once

#include "RandomCardsGenerator.h"

#include <vector>

// true - success, false - fail; container's length must be >= 52
bool initialize52Cards();
int getCardValue(int& sumOfOtherCards, bool addToSum = true);
