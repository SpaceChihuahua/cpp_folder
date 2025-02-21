#include <iostream>
#include <vector>
#include <algorithm>

constexpr int size = 4;
constexpr int listSize = 5;

struct Student
{
    const char* name = "";
    int marks[size] = {};
};

float printAvgMark(const Student& student)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += student.marks[i];
    }
    return static_cast<float>(sum) / size;
}

const Student* printBestStudent(const Student* studentList)
{
    const Student* bestStudent = &studentList[0];
    float bestAvgMark = printAvgMark(studentList[0]);
    for (int i = 0; i < size; i++)
    {
        float avgMark = printAvgMark(studentList[i]);
        if (avgMark > bestAvgMark)
        {
            bestAvgMark = avgMark;
            bestStudent = &studentList[i];
        }
    }
    return bestStudent;
}

int studentsPassed(const Student* studentList, int passGrade)
{
    int counter = 0;
    for (int i = 0; i < listSize; i++)
    {
        if (printAvgMark(studentList[i]) >= passGrade)
        {
            counter++;
        }
    }

    return counter;
}

int main()
{
    
    Student* studentList = new Student[listSize]{
        {"John", {54, 95, 76, 65}},
        {"Jack", {60, 62, 70, 65}},
        {"Jessica", {95, 100, 90, 88}},
        {"Mariam", {40, 60, 45, 50}},
        {"Judy", {77, 85, 80, 75}}
    };

    std::cout << "Student " << studentList[0].name << "'s average grade is: " << printAvgMark(studentList[0]) << std::endl;
    std::cout << "Student " << studentList[1].name << "'s average grade is: " << printAvgMark(studentList[1]) << std::endl;
    std::cout << "Student " << studentList[2].name << "'s average grade is: " << printAvgMark(studentList[2]) << std::endl;
    std::cout << "Student " << studentList[3].name << "'s average grade is: " << printAvgMark(studentList[3]) << std::endl;
    std::cout << "Student " << studentList[4].name << "'s average grade is: " << printAvgMark(studentList[4]) << std::endl;

    const Student* bestStudent = printBestStudent(studentList);
    std::cout << "The best student is: " << bestStudent->name << " with an average grade of: " << printAvgMark(*bestStudent) << std::endl;

    int passGrade = 60;
    std::cout << "Student's average grade should be at least " << passGrade << " to pass exams" << std::endl;
    std::cout << studentsPassed(studentList, passGrade) << " students passed exams" << std::endl;


}

