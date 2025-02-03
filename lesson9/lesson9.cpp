#include <iostream>
#include <cstring>
#include <string>

//function for task 1
void translateArray(int numbers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (numbers[i] > 0)
        {
            numbers[i] *= 2;
        }
        else
        {
            numbers[i] = 0;
        }
        std::cout << numbers[i] << ", ";
    }
    std::cout << std::endl;
}
//function for task 2
void toUppercase(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] > 96 && str[i] < 123) // ASCII code for 'a' is 97, and for 'z' is 122
        {
            str[i] -= 32;           
        }
        std::cout << str[i];
    }
    std::cout << std::endl;
}
//function for task 3
bool isPalindrom(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122)
        {
            return false; //characters are not letters
        }
    }
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main()
{
    //task 1
    const int arraySize = 10;
    int numbers[arraySize];
    std::cout << "Enter 10 numbers to fill an array: ";
    for (int i = 0; i < arraySize; i++)
    {
        std::cin >> numbers[i];
    }
    translateArray(numbers, arraySize);

    //task 2
    char myString[128];
    std::cout << "Please, enter a text: ";
    std::cin >> myString;
    toUppercase(myString);

    //task 3
    char userInput[8];

    std::cout << "Enter your word: ";
    std::cin >> userInput;

    if (isPalindrom(userInput))
    {
        std::cout << "it's a pallindrome\n";
    }
    else
    {
        std::cout << "it's not a pallindrome\n";
    }

    return 0;
}
