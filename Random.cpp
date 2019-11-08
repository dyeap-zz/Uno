#include <iostream>
#include <algorithm>
#include "Random.h"

Random::Random(int seed): seed(seed){
    generator.seed(seed);
}

Random::Random() {
    seed = generateSeed();
    generator.seed(seed);
}
int Random::generateSeed(){
    return std::chrono::system_clock::now().time_since_epoch().count();;
}

int Random::getNum() {
    return getRandomInt(0,2,generator);
}

template<typename RandomNumberGenerator>
int Random::getRandomInt(int min, int max, RandomNumberGenerator &rng) {
    return getRandomInt(min,max,generator);;
}




