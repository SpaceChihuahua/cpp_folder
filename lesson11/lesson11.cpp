#include <iostream>

constexpr unsigned int ROWS = 4;
constexpr unsigned int COLUMNS = 4;

bool find(int arr_2d[ROWS][COLUMNS], int toFind)
{
    for (int i = 0; i < COLUMNS; i++)
        for (int j = 0; j < ROWS; j++)
            if (arr_2d[i][j] == toFind)
                return true;
    return false;
}

enum class SortingDirection
{
    Ascending,
    Descending
};

bool isSorted(const int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool isSortedWDirection(const int* arr, int size, SortingDirection direction)
{
    if (direction == SortingDirection::Ascending)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] >= arr[i + 1])
                return false;
        }
    }
    else
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] <= arr[i + 1])
                return false;
        }
    }
    return true;
}

void traverseTopDownRightLeftByColumns(int arr_2d[ROWS][COLUMNS])
{
    for (int j = COLUMNS - 1; j >= 0; j--)
        for (int i = 0; i < ROWS; i++)
            std::cout << arr_2d[i][j] << " ";
}

void traverseLeftRightDownTopSwitchingByRows(int arr_2d[ROWS][COLUMNS])
{
    for (int i = ROWS - 1; i >=0; i--)
        if (i % 2 == 0)
        {
            for (int j = COLUMNS - 1; j >= 0; j--)
                std::cout << arr_2d[i][j] << " ";
        }
        else
        {
            for (int j = 0; j < COLUMNS; j++)
                std::cout << arr_2d[i][j] << " ";
        }
}

int main()
{
    //First task
    int arr_2d[ROWS][COLUMNS] = {
        {1, 2, 3, 4},
        {4, 3, 2, 1},
        {43, 13, 4, 12},
        {32, 45, 3, 1}
    };

    int elementToFind = 0;
    std::cout << "Please, enter the number you want to search for in array: ";
    std::cin >> elementToFind;

    if (find(arr_2d, elementToFind))
    {
        std::cout << "Element found!\n";
    }
    else
    {
        std::cout << "There is no such element!\n";
    }

    //Second task
    const int myArray[] = {1, 2, 3, 4, 5};

    std::cout << "Array is sorted in ascending order (simpler function): " << std::boolalpha << isSorted(myArray, 5) << std::endl;
    std::cout << "Array is sorted in ascending order: " << std::boolalpha << isSortedWDirection(myArray, 5, SortingDirection::Ascending) << std::endl;
    std::cout << "Array is sorted in descending order: " << std::boolalpha << isSortedWDirection(myArray, 5, SortingDirection::Descending) << std::endl;

    //Third task
    std::cout << "\nTraverse TopDownRightLeftByColumns\n";
    traverseTopDownRightLeftByColumns(arr_2d);
    std::cout << "\nTraverse LeftRightDownTopSwitchingByRows\n";
    traverseLeftRightDownTopSwitchingByRows(arr_2d);
}


