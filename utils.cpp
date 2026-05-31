#include <iostream>
#include <random>
#include "utils.h"

bool askPlayAgain()
{
    std::cout << "Would you like to play again? \n"
              << "1. Yes \n"
              << "2. No \n"
              << ">> ";
    int choice{};
    do
    {
        std::cin >> choice;
    } while (choice < 1 || choice > 2);
    if (choice == 1)
    {
        return true;
    }
    return false;
}

int getDifficultyLevel()
{
    std::cout << "Please select the difficulty level: \n"
              << "1. Easy (10 chances) \n"
              << "2. Medium (5 chances) \n"
              << "3. Hard (3 chances) \n"
              << ">> ";
    int choice{};
    do
    {
        std::cin >> choice;
    } while (choice < 1 || choice > 3);
    return choice;
}

int getUserGuess()
{
    std::cout << "Enter your guess: ";
    int input{};
    std::cin >> input;

    return input;
}

bool numGuessingMatch(int lives, int attempts, int randNumber)
{
    while (lives > 0)
    {
        attempts += 1;
        int guess = getUserGuess();
        if (guess > randNumber)
        {
            std::cout << "Incorrect! The number is less than " << guess << '\n';
        }
        else if (guess < randNumber)
        {
            std::cout << "Incorrect! The number is more than " << guess << '\n';
        }
        else
        {
            std::cout << "Congratulations! You guessed the correct number in " << attempts << " attempts. \n";
            return askPlayAgain();
        }
        lives -= 1;
        if (lives <= 0)
        {
            std::cout << "You lost. \n";
            return askPlayAgain();
        }
    }
    return false;
}

int randomNumber(int limit)
{
    static std::mt19937 rng{std::random_device{}()};
    std::uniform_int_distribution<> distr(1, limit);
    return distr(rng);
}

int returnDifficultyLives(int difficultyLevel)
{
    const int easy{1};
    const int medium{2};
    const int hard{3};

    switch (difficultyLevel)
    {
    case easy:
        return 10;
    case medium:
        return 5;
    case hard:
        return 3;
    default: // Values for bozos who somehow managed to break my code
        return 10;
    }
}

void welcomeMessage()
{
    std::cout << "Welcome to the Number Guessing Game! \n"
              << "I'm thinking of a number between 1 and 100. \n";
}
