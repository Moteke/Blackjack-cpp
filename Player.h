#pragma once
#include <string>
#include <vector>

struct Player {
    std::string name{};
    std::vector<int> cards;
    int sum{ 0 };
};