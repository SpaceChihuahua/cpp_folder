#include <iostream>
#include <algorithm>

void bubbleSort(int arr[], int size)
{
    for (int j = size; j > 0; j--)
    {
        for (int i = size - 1; i >= 0; i--)
            if (arr[i] < arr[i - 1])
            {
                std::swap(arr[i], arr[i - 1]);
            }
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

constexpr unsigned ROWS = 5;
constexpr unsigned COLUMNS = 5;

enum class SortingDirection
{
    byRows,
    byColumns
};

void print2D(int arr[ROWS][COLUMNS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void transposeArray(int arr[ROWS][COLUMNS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = i + 1; j < COLUMNS; j++)
        {
            std::swap(arr[i][j], arr[j][i]);
        }
    }
}

void sort(int arr[ROWS][COLUMNS], SortingDirection direction)
{
    switch (direction)
    {
    case SortingDirection::byRows:
        for (int i = 0; i < ROWS; i++)
        {
            std::sort(arr[i], arr[i] + COLUMNS);
        }
        break;
    case SortingDirection::byColumns:
        transposeArray(arr); //swap rows and columns, so it's easier to sort numbers
        for (int i = 0; i < ROWS; i++)
        {
            std::sort(arr[i], arr[i] + COLUMNS);
        }
        transposeArray(arr); // swap back to the original form with already sorted numbers
        break;
    }
}

int main()
{
    //first task
    constexpr unsigned size = 5;
    int myArray[size] = { 5, 3, 6, 2, 1 };
    std::cout << "Array before sorting: \n";
    print(myArray, size);
    bubbleSort(myArray, size);
    std::cout << "Array after sorting: \n";
    print(myArray, size);

    //second task
    int myTwoDimArray[ROWS][COLUMNS] = {
        {4 ,3 ,6, 7, 8},
        {4, 5, 7, 9, 2},
        {8, 6, 9, 1, 3},
        {4, 23, 5, 2, 3},
        {5, 8, 9, 2, 4}
    };
    std::cout << "Before sorting by rows: \n";
    print2D(myTwoDimArray);
    sort(myTwoDimArray, SortingDirection::byRows);
    std::cout << "After sorting by rows: \n";
    print2D(myTwoDimArray);

    //third task (by columns)
    int myTwoDimArray2[ROWS][COLUMNS] = {
        {5 ,3 ,15, 7, 8},
        {4, 5, 7, 9, 2},
        {3, 6, 17, 1, 55},
        {4, 23, 5, 11, 3},
        {1, 8, 93, 22, 15}
    };
    std::cout << "Before sorting by columns: \n";
    print2D(myTwoDimArray2);
    sort(myTwoDimArray2, SortingDirection::byColumns);
    std::cout << "After sorting by columns: \n";
    print2D(myTwoDimArray2);
}
