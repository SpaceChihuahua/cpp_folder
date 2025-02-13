#include <iostream>

void swapPtr(int& a, int& b)
{
    int i = a; //store variable 'a' initial value before it is changed
    a = b;
    b = i;
}

void swapRef(int* a, int* b)
{
    int i = *a; //store variable 'a' initial value before it is changed
    *a = *b;
    *b = i;  
}

bool find(const int* arr, int size, int elem)
{
    const int* endOfArray = arr + size;
    while (arr < endOfArray)
    {
        if (*arr == elem)
        {
            return true;
        }
        arr++;
    }
    return false;
}

int main()
{
    //First swap
    int a = 1;
    int b = 2;
    std::cout << "Variables before swap: \n";
    std::cout << "Variable a value: " << a << std::endl;
    std::cout << "Variable a address: " << &a << std::endl;
    std::cout << "Variable b value: " << b << std::endl;
    std::cout << "Variable b address: " << &b << std::endl;

    swapPtr(a, b);

    std::cout << "Variables after swap: \n";
    std::cout << "Variable a value: " << a << std::endl;
    std::cout << "Variable a address: " << &a << std::endl;
    std::cout << "Variable b value: " << b << std::endl;
    std::cout << "Variable b address: " << &b << std::endl;

    //Second swap
    int c = 3;
    int d = 4;

    std::cout << "Variables before swap: \n";
    std::cout << "Variable c value: " << c << std::endl;
    std::cout << "Variable c address: " << &c << std::endl;
    std::cout << "Variable d value: " << d << std::endl;
    std::cout << "Variable d address: " << &d << std::endl;
    swapRef(&c, &d);
    std::cout << "Variables after swap: \n";
    std::cout << "Variable c value: " << c << std::endl;
    std::cout << "Variable c address: " << &c << std::endl;
    std::cout << "Variable d value: " << d << std::endl;
    std::cout << "Variable d address: " << &d << std::endl;

    //pointer arithmetics 
    const int arraySize = 10;
    int myArray[arraySize];
    int elem = 0;

    std::cout << "Enter 10 numbers to fill an array: ";
    for (int i = 0; i < arraySize; i++)
    {
        std::cin >> myArray[i];
    }

    std::cout << "Enter a number for which we should search within an array: ";
    std::cin >> elem;
        
    int* ptrToMyArray = &myArray[0];

    if (find(ptrToMyArray, arraySize, elem))
    {
        std::cout << "Element is found!\n";
    }
    else
    {
        std::cout << "No such element!\n";
    }

    return 0;

}
