#include <iostream>
#include <string>
#include <utility>
#include <vector>


#include "HEADERS/Day1.h"
#include "HEADERS/Day2.h"
#include "HEADERS/Day3.h"
#include "HEADERS/Day4.h"
#include "HEADERS/Day5.h"
#include "HEADERS/Day6.h"
#include "HEADERS/Day7.h"


using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::vector;


void Day1();
void Day2();
void Day3();
void Day4();
void Day5();
void Day6();
void Day7();


int main()
{
    Day1();
    Day2();
    Day3();
    Day4();
    Day5();
    Day6();
    Day7();
}

void Day1()
{
    vector<int> day1Input = GetExpenses("INPUT-FILES/Day-1-Input.txt");
    cout << "Day 1, Task 1: " << Day1Task1(day1Input) << endl;
    cout << "Day 1, Task 2: " << Day1Task2(day1Input) << endl;
}

void Day2()
{
    vector<pair<string, string>> day2Input = GetPasswordPairs("INPUT-FILES/Day-2-Input.txt");
    cout << "Day 2, Task 1: " << FindValidPasswordsPart1(day2Input) << endl;
    cout << "Day 2, Task 2: " << FindValidPasswordsPart2(day2Input) << endl;
}

void Day3()
{
    vector<string> day3Input = GetTrees("INPUT-FILES/Day-3-Input.txt");
    cout << "Day 3, Task 1: " << CountEncounteredTrees(day3Input, 3) << endl;
    //day3Input = GetStringVectorFromFile("INPUT-FILES/Day-3-Input-2.txt");
    cout << "Day 3, Task 2: " << CheckMultipleSlopes(day3Input, CreateRules()) << endl;
}

void Day4()
{
    vector<string> day4Input = GetCredentials("INPUT-FILES/Day-4-Input.txt");
    //day4Input = GetCredentials("INPUT-FILES/Day-4-Input-2.txt");
    //vector<string> day4Input = GetCredentials("INPUT-FILES/Day-4-Input-3-Invalid (copy).txt");
    cout << "Day 4, Task 1: " << CountContainsRequiredFields(day4Input, GenerateRequiredFields()) << endl;
    cout << "Day 4, Task 2: " << CountValidCredentials(day4Input, GenerateRequiredFields()) << endl;
}

void Day5()
{
    vector<string> day5Input = GetTickets("INPUT-FILES/Day-5-Input.txt");
    //day5Input = GetTickets("INPUT-FILES/Day-5-Input-2.txt");
    cout << "Day 5, Task 1: " << GetMaxSeatID(day5Input) <<  endl;
    cout << "Day 5, Task 2: " << FindMySeatID(day5Input) << endl;
}

void Day6()
{
    vector<string> day6Input = GetQuestionnaireResponses("INPUT-FILES/Day-6-Input.txt");
    //day6Input = GetQuestionnaireResponses("INPUT-FILES/Day-6-Input-2.txt");
    cout << "Day 6, Task 1: " << GetTotalYesAnswers(day6Input) << endl;
    cout << "Day 6, Task 2: " << GetUnanimousAnswers(day6Input) << endl;
}

void Day7()
{

}
