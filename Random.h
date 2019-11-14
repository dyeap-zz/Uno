#ifndef UNO_RANDOM_H
#define UNO_RANDOM_H
#include <iostream>
#include <random>


class Random{
    template<typename RandomNumberGenerator>
    int getRandomInt(int min, int max, RandomNumberGenerator& rng) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }
public:
    Random(int seed);
    Random();

    int generateSeed();
    int getNum(int min, int max);
    std::minstd_rand getGenerator();

private:
    int seed;
    std::minstd_rand generator;
};
#endif //UNO_RANDOM_H
