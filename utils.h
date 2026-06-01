#pragma once

bool askPlayAgain();
int getDifficultyLevel();
int getUserGuess();
int intInputGuard(int initial, int limit);
bool numGuessingMatch(int lives, int attempts, int randNumber);
int randomNumber(int limit);
int returnDifficultyLives(int choice);
void welcomeMessage();
