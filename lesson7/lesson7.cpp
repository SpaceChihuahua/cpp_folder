#include <iostream>
#include <ctime>
#include <algorithm>

//Game rules

enum class RoundResult
{
    Loss,
    Win,
    Draw
};

static RoundResult Compare(char a, char b)
{
    if (a == 'r' && b == 's') return RoundResult::Win;
    if (a == 's' && b == 'r') return RoundResult::Loss;
    if (a == 'p' && b == 'r') return RoundResult::Win;
    if (a == 'r' && b == 'p') return RoundResult::Loss;
    if (a == 's' && b == 'p') return RoundResult::Win;
    if (a == 'p' && b == 's') return RoundResult::Loss;
    if (a == b) return RoundResult::Draw;
}

char GenerateChoice()
{
    int GenRange = 3;
    const int GenNum = std::rand() % (GenRange);
    switch (GenNum)
    {
    case 0: return 'r';
    case 1: return 's';
    case 2: return 'p';
    }
}

int main()
{
    int N = 0;
    char PlayerChoice = 0;
    char GameChoice = 0;

    std::srand(std::time(nullptr));
    const int GenRange = 3;
    const int GenNum = std::rand() % (GenRange); // 0-2

    while (true)
    {   
        int WinCounter = 0;
        int LossCounter = 0;
        int DrawCounter = 0;
        std::cout << "Enter number of rounds for this game (-1 to quit): ";
        std::cin >> N;
        if (N == -1)
        {
            break;
        }
        for (int i = 1; i <= N; i++)
        {
            //Player turn
            do
            {
                std::cout << "Choose your option: rock (r), paper (p), scissors (s) \n";
                std::cin >> PlayerChoice;
            } while (PlayerChoice != 'r' && PlayerChoice != 'p' && PlayerChoice != 's');

            std::cout << "Your choice is " << PlayerChoice << std::endl;

            //Game's turn
            GameChoice = GenerateChoice();

            std::cout << "Game choice is " << GameChoice << std::endl;

            //Deciding a result of a round
            RoundResult result = (Compare(PlayerChoice, GameChoice));
            switch (result)
            {
            case RoundResult::Win:
                std::cout << "You WON \n\n";
                WinCounter += 1;
                break;
            case RoundResult::Loss:
                std::cout << "You LOST \n\n";
                LossCounter += 1;
                break;
            case RoundResult::Draw:
                std::cout << "DRAW \n\n";
                DrawCounter += 1;
                break;
            }
        }
        //Calculating game result
        std::cout << "Your final stats: \n";
        std::cout << "Number of rounds: " << N << std::endl;
        std::cout << "Number of wins: " << WinCounter << std::endl;
        std::cout << "Number of losses: " << LossCounter << std::endl;
        std::cout << "Number of draws: " << DrawCounter << std::endl << std::endl;
        if (WinCounter > LossCounter)
        {
            std::cout << "Congratulations! You've WON! \n";
        }
        else if (WinCounter < LossCounter)
        {
            std::cout << "Oh no! You've LOST! \n";
        }
        else
        {
            std::cout << "Seems that the winner is not defined in this match! \n";
        }
        std::cout << "Thanks for playing! Start a new game or type -1 to quit... \n\n";
    }
    return 0;
}

