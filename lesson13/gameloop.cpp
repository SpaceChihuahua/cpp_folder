#include "gameloop.h"
#include <iostream>
#include <ctime>
#include <fstream>

constexpr unsigned int wordSize = 5;

void initWord(std::vector<char>& wordToGuess)
{
    wordToGuess.clear();
    std::string filename = "WordsDataBase.txt";
    std::ifstream file(filename);
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    std::srand(std::time(0));
    int randomLineNumber = std::rand() % lines.size();

    wordToGuess.assign(lines[randomLineNumber].begin(), lines[randomLineNumber].end());

}

void addUserInput(std::vector<char>& userInput, std::string userWord)
{
    //done and tested
    userInput.clear();
    while (true)
    {
        std::cout << "Enter your word: ";
        std::getline(std::cin, userWord);
        if (userWord.length() > wordSize)
        {
            userWord = userWord.substr(0, wordSize);
            break;
        }
        else if (userWord.length() < wordSize)
        {
            std::cout << "Please, enter the word that consists of 5 letters!\n";
        }
        else
        {
            break;
        }
    }
    userInput.assign(userWord.begin(), userWord.end());
}

void compareWords(std::vector<char> wordToGuess, std::vector<char> userInput, std::vector<char>& showProgress)
{
    int letterCount[26] = { 0 }; //array which we'll use to track how much same letters guessed word has and don't allow to make duplicates on result vector
    //first check if any letters are in the same position
    for (size_t i = 0; i < wordSize; i++)
    {
        if (wordToGuess[i] == userInput[i])
        {
            showProgress[i] = std::toupper(userInput[i]);
        }
        else
        {
            showProgress[i] = '*';
            letterCount[wordToGuess[i] - 'a']++;
        }
    }
    //then check if there are any equal letters in the different positions
    for (size_t i = 0; i < wordSize; i++)
    {
        for (size_t j = 0; j < wordSize; j++)
        {
            if (wordToGuess[i] == userInput[j] && showProgress[j] == '*')
            {
                int index = userInput[j] - 'a';
                if (letterCount[index] > 0)
                {
                    showProgress[j] = std::tolower(userInput[j]);
                    letterCount[index]--;
                }
            }
        }
    }
}

void printRoundResult(std::vector<char> showProgress)
{
    std::cout << "Result: ";
    for (char c : showProgress) {
        std::cout << c;
    }
    std::cout << std::endl << std::endl;
}

bool wordGuessed(std::vector<char> wordToGuess, std::vector<char> userInput)
{
    for (size_t i = 0; i < wordSize; i++)
    {
        if (wordToGuess[i] != userInput[i])
            return false;
    }
    return true;
}