#include <random.hpp>

int random::randInt(int min, int max) {
    int digit = std::uniform_int_distribution<int>(min, max)(rgen);

    if(digit%2 == 0 && digit&4 == 0){
        digit = std::uniform_int_distribution<int>(min, max)(rgen);
    }

    return digit;
}

std::random_device random::rgen;