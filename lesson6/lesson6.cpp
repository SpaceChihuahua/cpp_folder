#include <iostream>
#include <cctype>

int main()
{   
    //First Task
    int a1 = 0;
    int d = 0;
    unsigned int n = 0;
    int InputN = 0;

    std::cout << "Enter first progression number: ";
    std::cin >> a1;
    std::cout << "Enter progression step: ";
    std::cin >> d;
    do
    {
        std::cout << "Enter number of members in progression: ";
        std::cin >> InputN;
        if (InputN <= 0)
        {
            std::cout << "Please, use positive integer! \n";
        }
        else
        {
            n = static_cast<unsigned int>(InputN);
        } 
    } while (InputN <= 0);

    for (int i = 1; i <= n; i++)
    {
        std::cout << a1 + (i - 1) * d << ", ";
    }
    std::cout << std::endl << std::endl;
    
    //SecondTask
    unsigned int Width = 0;
    unsigned int LinesNumber = 0; //height
    int InputWidth = 0;
    int InputLinesNumber = 0;
    do
    {
        std::cout << "Enter width and height of figures we will draw \n";
        std::cout << "Width: ";
        std::cin >> InputWidth;
        std::cout << "Height: ";
        std::cin >> InputLinesNumber;
        if (InputWidth <= 0 || InputLinesNumber <= 0)
        {
            std::cout << "Please, use positive integers!!! \n";
        }
        else
        {
            Width = static_cast<unsigned int>(InputWidth);
            LinesNumber = static_cast<unsigned int>(InputLinesNumber);
        }
    } while (InputWidth <= 0 || InputLinesNumber <= 0);
    std::cout << std::endl;
    //a
    std::cout << "Flipped triangle \n\n";
    for (int i = 0; i < Width; i++)
    {
        for (int j = i; j < Width; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //b
    std::cout << "Triangle \n\n";
    for (int i = 1; i <= Width; i++)
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //c
    std::cout << "Rectangle \n\n";
    for (int i = 0; i < LinesNumber; i++)
    {
        for (int j = 0; j < Width; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //d
    std::cout << "Parallelogram \n\n";
    for (int i = 0; i < LinesNumber; i++)
    {   
        for (int j = 0; j < i; j++)
        {
            std::cout << " ";
        }
        for (int j = 0; j < Width; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //e
    std::cout << "Bool triangle \n\n";

    for (int i = 1; i <= Width; i++)
    {
        bool Symbol = (i % 2 != 0);
        for (int j = 0; j < i; j++)
        {
            std::cout << Symbol;
            Symbol = !Symbol;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //Third task
    char MySymbol = 0;
    int Number = 0;
    int Sum = 0;
    while (true)
    {
        std::cout << "Enter your symbol: ";
        std::cin >> MySymbol;
        if (islower(MySymbol))
        {
            MySymbol = toupper(MySymbol);
            std::cout << MySymbol << std::endl;
        }
        else if (isdigit(MySymbol))
        {
            Number = MySymbol - '0';
            Sum = Sum + Number;
            std::cout << "Overall sum is: " << Sum << std::endl;
        }
        else if (MySymbol == '.')
        {
            break;
        }
        else
        {
            std::cout << "This symbol cannot be proccessed, please, enter another one (Enter symbol '.' for exit) \n";
        }
    }

    //Fourth task
    unsigned int Fibonacci = 0;
    unsigned int PreviousNumber = 0;
    unsigned int CurrentNumber = 1;
    unsigned int CycleResult = 0;

    std::cout << "Enter Fibonacci sequence number position: ";
    std::cin >> Fibonacci;
   
        if (Fibonacci == 1)
        {
            std::cout << "Your number is: 1 \n";
        }
        else
        {
            for (int n = 2; n <= Fibonacci; n++)
            {
                CycleResult = PreviousNumber + CurrentNumber;
                PreviousNumber = CurrentNumber; 
                CurrentNumber = CycleResult; 
            } 
            std::cout << "Your number is: " << CurrentNumber << std::endl;
        }

    //Fifth task
    unsigned int UserInput = 0;
    unsigned int FirstNumber = 1;
    unsigned int Factorial = 1;
    std::cout << "Enter value for calculating factorial: ";
    std::cin >> UserInput;
    for (int i = 1; i <= UserInput; i++)
    {
        Factorial = Factorial * FirstNumber;
        FirstNumber = FirstNumber + 1;
    }
    std::cout << Factorial << std::endl;
    return 0;
}

