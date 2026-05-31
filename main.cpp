#include <iostream>
#include "utils.h"

int main()
{
    welcomeMessage();
    bool keepPlaying{true};
    const int limit{100};

    while (keepPlaying)
    {
        int lives = returnDifficultyLives(getDifficultyLevel());
        int randNumber = randomNumber(limit); // Generates a random number from 1 to limit
        int attempts{};

        keepPlaying = numGuessingMatch(lives, attempts, randNumber);
    }
    return 0;
}
