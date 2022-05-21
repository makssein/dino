#pragma once
#include <random>

class random {
public:
    static int randInt(int min, int max);
private:
    static std::random_device rgen;
};