#pragma once
#include <vector>
#include <string>

void initWord(std::vector<char>& wordToGuess);

void addUserInput(std::vector<char>& userInput, std::string userWord);

void compareWords(std::vector<char> wordToGuess, std::vector<char> userInput, std::vector<char>& showProgress);

void printRoundResult(std::vector<char> showProgress);

bool wordGuessed(std::vector<char> wordToGuess, std::vector<char> userInput);