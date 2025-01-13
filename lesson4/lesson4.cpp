#include <iostream>
#include <algorithm>

enum class Months {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main()
{
    //First task
    float a = 0.f;
    float b = 0.f;
    float c = 0.f;
    std::cout << "Enter three numbers: \n";
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    std::cout << "Max of these numbers is: " << std::max(a, std::max(b, c)) << std::endl;

    //Second task
    int MyNumber = 0;
    std::cout << "Enter a number: \n";
    std::cin >> MyNumber;

    if ((MyNumber % 5 == 0) && (MyNumber % 11 == 0))
    {
        std::cout << "This number divides by 5 and 11 without a remainder" << std::endl;
    }
    else
    {
        std::cout << "This number cannot be divided by 5 or/and 11 without remainder" << std::endl;
    }

    //third task
    float FirstAngle = 0.f;
    float SecondAngle = 0.f;
    float ThirdAngle = 0.f;

    while (FirstAngle == 0.f || SecondAngle == 0.f || ThirdAngle == 0.f)
    {
        std::cout << "Enter values for a triangle angles: \n";
        std::cin >> FirstAngle;
        std::cin >> SecondAngle;
        std::cin >> ThirdAngle;
    }

    FirstAngle = fabs(FirstAngle);
    SecondAngle = fabs(SecondAngle);
    ThirdAngle = fabs(ThirdAngle);



    if ( FirstAngle + SecondAngle + ThirdAngle == 180)
    {
        std::cout << "You can form a triangle with these angles \n";
    }
    else
    {
        std::cout << "These angles cannot form a triangle \n";
    }
    
    //fourth task

    int MonthNumber = 0;
    
    do
    {
        std::cout << "Enter month number (from 1 to 12): ";
        std::cin >> MonthNumber;
    } while (MonthNumber < 1 || MonthNumber > 12);

    if (MonthNumber == 1 || MonthNumber == 2 || MonthNumber == 12)
    {
        std::cout << "Winter \n";
    }
    else if (MonthNumber == 3 || MonthNumber == 4 || MonthNumber == 5)
    {
        std::cout << "Spring \n";
    }
    else if (MonthNumber == 6 || MonthNumber == 7 || MonthNumber == 8)
    {
        std::cout << "Summer \n";
    }
    else if (MonthNumber == 9 || MonthNumber == 10 || MonthNumber == 11)
    {
        std::cout << "Autumn \n";
    }

    //Fifth task 
    int NumberOne = 0;
    int NumberTwo = 0;
    std::cout << "Enter two numbers: \n";
    std::cin >> NumberOne;
    std::cin >> NumberTwo;
    float MinNumber = (NumberOne < NumberTwo) ? NumberOne : NumberTwo;
    std::cout << "Lesser of these numbers is: " << MinNumber << std::endl;

    //Sixth task
    int MonthNum = 0;
    do
    {
        std::cout << "Enter month number (from 1 to 12): ";
        std::cin >> MonthNum;
    } while (MonthNum < 1 || MonthNum > 12);

    Months Month = static_cast<Months>(MonthNum);
    switch (Month)
    {
    case Months::January:std::cout << "January";
        break;
    case Months::February:std::cout << "February";
        break;
    case Months::March:std::cout << "March";
        break;
    case Months::April:std::cout << "April";
        break;
    case Months::May:std::cout << "May";
        break;
    case Months::June:std::cout  << "June";
        break;
    case Months::July:std::cout << "July";
        break;
    case Months::August:std::cout << "August";
        break;
    case Months::September:std::cout << "September";
        break;
    case Months::October:std::cout << "October";
        break;
    case Months::November:std::cout << "November";
        break;
    case Months::December:std::cout << "December";
        break;
    }
    std::cout << " is your month" << std::endl;

    return 0;

}


