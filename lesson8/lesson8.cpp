#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

void CountNumbers(int Count) 
{
    int PositiveNumbersCounter = 0;
    int NegativeNumbersCounter = 0;
    int ZerosCounter = 0;
    int Number = 0;

    std::cout << "Enter " << Count << " numbers \n";

    for (int i = 0; i < Count; ++i) 
    {
        std::cin >> Number;
        if (Number > 0) 
        {
            ++PositiveNumbersCounter;
        }
        else if (Number < 0) 
        {
            ++NegativeNumbersCounter;
        }
        else 
        {
            ++ZerosCounter;
        }
    }

    std::cout << "Positive: " << PositiveNumbersCounter << std::endl;
    std::cout << "Negative: " << NegativeNumbersCounter << std::endl;
    std::cout << "Zeros: " << ZerosCounter << std::endl;
}

int FactorialCycle(int NumberForCycle)
{
    int Factorial = 1;
    for (int i = 2; i <= NumberForCycle; i++)
    {
        Factorial *= i;
    }
    return Factorial;
}

int FactorialRecursion(int NumberForRecursion)
{
    if (NumberForRecursion <= 1)
    {
        return 1;
    }
    return NumberForRecursion * FactorialRecursion(NumberForRecursion - 1);
}

float GetArea(float Radius)
{
    return M_PI * pow(Radius, 2);
}

float GetCircumference(float Radius)
{
    return 2 * M_PI * Radius;
}




int main()
{
    int UserNumberInput = 0;
    
    //Counter of positive, negative and zero values
    do
    {
        std::cout << "How many numbers do you want to enter?" << std::endl;
        std::cin >> UserNumberInput;

        if (UserNumberInput > 0)
        {
            CountNumbers(UserNumberInput);
        }
        else
        {
            std::cout << "Wrong value, please enter positive number!" << std::endl;
        }
    } while (UserNumberInput <= 0);
    
    //Factorial
    do
    {
        std::cout << "Enter positive number to get its' factorial: ";
        std::cin >> UserNumberInput;
        if (UserNumberInput > 0)
        {
            std::cout << "Factorial via cycle function: " << FactorialCycle(UserNumberInput) << std::endl;
            std::cout << "Factorial via recursive function: " << FactorialRecursion(UserNumberInput) << std::endl;
        }
        else
        {
            std::cout << "Wrong value, please enter positive number!" << std::endl;
        }
        
    } while (UserNumberInput <= 0);
    
    //Circle
    float CircleRadius = 0;
    do
    {
        std::cout << "Enter circle radius: ";
        std::cin >> CircleRadius;
        if (CircleRadius > 0)
        {
            std::cout << "Circle area is: " << GetArea(CircleRadius) << std::endl;
            std::cout << "Circle circumference is: " << GetCircumference(CircleRadius) << std::endl;
        }
        else
        {
            std::cout << "Wrong value, please enter positive number!" << std::endl;
        }

    } while (CircleRadius <= 0);
}


