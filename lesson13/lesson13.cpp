#include "gameloop.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

constexpr unsigned int wordSize = 5;

int main()
{
    std::cout << "In this game you need to guess a word, that is hidden under ***** symbols\nRULES:" << std::endl <<
        "After each move computer compares word that you wrote with the hidden word. If there are letters in your word that hidden word " << std::endl <<
        "contains, they will be shown in lower case. If you managed to guess a letter in correct position, it will be shown in upper case." << std::endl <<
        "Game continues until the hidden word is guessed correctly." << std::endl << std::endl;

    std::vector<char> wordToGuess;
    std::vector<char> userInput;
    std::vector<char> showProgress(wordSize, '*');
    while (true)
    {
        int menuChoice = 0;
        std::cout << "1 - Start the game\n";
        std::cout << "0 - Quit\n\n";
        std::cin >> menuChoice;
        if (menuChoice == 0)
        {
            std::cout << "Thanks for playing!\n";
            return 0;
        }

        initWord(wordToGuess);
        int roundCounter = 0;

        //GameLoop
        while (true)
        {
            std::string userWord = "a";
            addUserInput(userInput, userWord);
            roundCounter++;
            compareWords(wordToGuess, userInput, showProgress);
            printRoundResult(showProgress);
            if (wordGuessed(wordToGuess, userInput))
            {
                std::cout << "Great! You guessed the word correctly in " << roundCounter << " tries!\n";
                break;
            }
        }
    }
    return 0;
}
