#include <iostream>
#include <math.h>

int main()
{
    //First task
    int Time = 0;
    int Hours = 0;
    int Minutes = 0;
    int Seconds = 0;
    std::cout << "Enter how many time you spent in game in seconds: ";
    std::cin >> Time;

    Hours = Time / 3600;
    Minutes = (Time % 3600) / 60;
    Seconds = (Time % 3600) % 60;
    std::cout << "You spent in game: " << Hours << " hours " << Minutes << " minutes " << Seconds << " seconds " << std::endl;

    //second task
    float FirstNumber = 0.f;
    float SecondNumber = 0.f;
    float ThirdNumber = 0.f;

    std::cout << "Enter three numbers: \n";
    std::cin >> FirstNumber;
    std::cin >> SecondNumber;
    std::cin >> ThirdNumber;

    std::cout << "Sum is: " << FirstNumber + SecondNumber + ThirdNumber << std::endl;
    std::cout << "Product is: " << FirstNumber * SecondNumber * ThirdNumber << std::endl;
    std::cout << "Arithmetic mean is: " << (FirstNumber + SecondNumber + ThirdNumber) / 3 << std::endl;

    //third task
    float One = 0.f;
    float Two = 0.f;

    std::cout << "Enter two numbers: \n";
    std::cin >> One;
    std::cin >> Two;

    bool lessThan = (One < Two);
    bool equal = (One == Two);
    bool moreThan = (One > Two);
    bool lessOrEqual = (One <= Two);

    std::cout << "First number is smaller than second: " << std::boolalpha << lessThan << std::endl;
    std::cout << "First number is equal to second: " << std::boolalpha << equal << std::endl;
    std::cout << "First number is bigger than second: " << std::boolalpha << moreThan << std::endl;
    std::cout << "First number is smaller than second, or equal to it: " << std::boolalpha << lessOrEqual << std::endl;

    //fourth task
    int Width = 0;
    int Height = 0;

    std::cout << "Enter rectangle's width and height: \n";
    std::cout << "Width: ";
    std::cin >> Width;
    std::cout << "Height: ";
    std::cin >> Height;
    Width = fabs(Width);
    Height = fabs(Height);

    if (Width == 0 || Height == 0)
    {
        std::cout << "At least one of the sides equals zero, so it's basically a line segment, not a rectangle, so I won't do anything with it \n";
    }
    else
    {
        std::cout << "If you entered negative numbers, I assume you meant positive ones, so here are your calculations \n";
        std::cout << "Perimeter is: " << 2 * Width + 2 * Height << std::endl;
        std::cout << "Square is: " << Width * Height << std::endl;
    }

    //fifth task
    double pi = 2 * acos(0.0);
    float Radius = 0.f;

    std::cout << "Enter circle's radius: \n";
    std::cin >> Radius;
    Radius = fabs(Radius);
    std::cout << "Circle radius is: " << pi * pow(Radius, 2) << std::endl;

    return 0;
}
