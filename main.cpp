#include <iostream>
#include <utility>
#include <vector>

#include "Day1.h"
#include "Day2.h"
#include "Day3.h"

using std::cout;
using std::endl;
using std::pair;
using std::vector;

void Day1();
void Day2();
void Day3();

int main()
{
    Day1();
    Day2();
    Day3();
}

void Day1()
{
    vector<int> day1Input = GetIntVectorFromFile("Day-1-Input.txt");
    cout << "Day 1, Task 1: " << Day1Task1(day1Input) << endl;
    cout << "Day 1, Task 2: " << Day1Task2(day1Input) << endl;
}

void Day2()
{
    vector<pair<string, string>> day2Input = GetStringPairVectorFromFile("Day-2-Input.txt");
    cout << "Day 2, Task 1: " << FindValidPasswordsPart1(day2Input) << endl;
    cout << "Day 2, Task 2: " << FindValidPasswordsPart2(day2Input) << endl;
}

void Day3()
{
    vector<string> day3Input = GetStringVectorFromFile("Day-3-Input.txt");
    cout << "Day 3, Task 1: " << CountEncounteredTrees(day3Input, 3) << endl;
    //day3Input = GetStringVectorFromFile("Day-3-Input-2.txt");
    cout << "Day 3, Task 2: " << CheckMultipleSlopes(day3Input, CreateRules()) << endl;
}
