#ifndef DAY1_H
#define DAY1_H


#include <fstream>
#include <string>
#include <utility>
#include <vector>


using std::fstream;
using std::pair;
using std::string;
using std::vector;


vector<int> GetExpenses(string fileName)
{
    fstream myFile(fileName);
    vector<int> numbers;
    if(myFile)
    {
        string line;
        int temp;
        while (getline(myFile, line))
        {
            if (line.size() > 0)
            {
                temp = stoi(line);
                numbers.push_back(temp);
            }
        }
    }
    myFile.close();
    return numbers;
}


int Day1Task1(vector<int> numbers)
{
    int num1 = 0, num2 = 0;
    for (long unsigned int i = 0; i < numbers.size(); i++)
    {
        for (long unsigned int j = i; j < numbers.size(); j++)
        {
            if (numbers[i] + numbers[j] == 2020)
            {
                num1 = numbers[i];
                num2 = numbers[j];
            }
        }
    }
    return (num1 * num2);
}


int Day1Task2(vector<int> numbers)
{
    int num1 = 0, num2 = 0, num3 = 0;
    for (long unsigned int i = 0; i < numbers.size(); i++)
    {
        for (long unsigned int j = i; j < numbers.size(); j++)
        {
            for (long unsigned int k = j; k < numbers.size(); k++)
            {
                if (numbers[i] + numbers[j] + numbers[k] == 2020)
                {
                    num1 = numbers[i];
                    num2 = numbers[j];
                    num3 = numbers[k];
                }
            }
        }
    }
    return (num1 * num2 * num3);
}


#endif
