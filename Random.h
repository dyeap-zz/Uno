#ifndef UNO_RANDOM_H
#define UNO_RANDOM_H
#include <iostream>
#include <random>
class Random{
    template<typename RandomNumberGenerator>
    int getRandomInt(int min, int max, RandomNumberGenerator& rng);
public:
    Random(int seed);
    Random();

    int generateSeed();
    int getNum();
private:
    int seed;
    int num;
    std::minstd_rand generator;
};
#endif //UNO_RANDOM_H
