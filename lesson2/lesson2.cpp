#include <iostream>
#include <iomanip>

enum class Weekday : int {
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main()
{
    //first task

    std::cout << "First task" << std::endl;
    int a;
    int b;
    std::cout << "Enter first number: " << std::endl;
    std::cin >> a;
    std::cout << "Enter second number: " << std::endl;
    std::cin >> b;
    std::swap(a, b);
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    //second task

    std::cout << "Second task" << std::endl;
    double c = 5.62354234234;
    std::cout << std::setprecision(15) << c << std::endl;
    std::cout << (int)c << std::endl;
    std::cout << std::setw(20) << std::right << std::setfill('$') << c << std::endl;

    ////third task

    std::cout << "Third task" << std::endl;

    double d = 19.345987345;
    std::cout << std::fixed << std::setprecision(2) << d << std::endl;
    std::cout << std::fixed << std::setprecision(5) << d << std::endl;
    std::cout << std::fixed << std::setprecision(10) << d << std::endl;
    std::cout << std::scientific << d << std::endl;
    std::cout << std::hexfloat << d << std::endl;

    //Fourth task

    std::cout << "Fourth task" << std::endl;

    for (int i = static_cast<int>(Weekday::Monday); i <= static_cast<int>(Weekday::Sunday); ++i) {
        Weekday day = static_cast<Weekday>(i);

        std::cout << "Day " << i << " corresponds to ";

        switch (day) {
        case Weekday::Monday:std::cout << "Monday"; break;
        case Weekday::Tuesday:std::cout << "Tuesday"; break;
        case Weekday::Wednesday:std::cout << "Wednesday"; break;
        case Weekday::Thursday:std::cout << "Thursday"; break;
        case Weekday::Friday:std::cout << "Friday"; break;
        case Weekday::Saturday:std::cout << "Saturday"; break;
        case Weekday::Sunday:std::cout << "Sunday"; break;
        }

        std::cout << std::endl;
    }

   //Fifth task

    std::cout << "Fifth task" << std::endl;

    int MyNumber;
    std::cout << "Enter a number: ";
    std::cin >> MyNumber;

    bool MyBoolean = static_cast<bool>(MyNumber);

    std::cout << "Boolean is: " << std::boolalpha << MyBoolean << std::endl;



    return 0;
}


