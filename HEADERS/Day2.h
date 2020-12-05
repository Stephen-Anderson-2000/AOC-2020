#ifndef DAY2_H
#define DAY2_H


#include <fstream>
#include <string>
#include <utility>
#include <vector>


using std::fstream;
using std::getline;
using std::pair;
using std::string;
using std::vector;


pair<int, int> FindMinMax(string);
int CountOccurences(char, string);


vector<pair<string, string>> GetPasswordPairs(string fileName)
{
    fstream myFile(fileName);
    pair<string, string> passwordPair;
    vector<pair<string, string>> pairs;
    if(myFile)
    {
        string line;
        while (getline(myFile, line))
        {
            size_t pos = line.find(':');
            if (line.size() > 0 && pos != string::npos)
            {
                passwordPair.first = line.substr(0, pos);
                passwordPair.second = line.substr(pos);
                pairs.push_back(passwordPair);
            }
        }
    }
    myFile.close();
    return pairs;
}


int FindValidPasswordsPart1(vector<pair<string, string>> pairs)
{
    int validPasswords = 0;
    for (unsigned int i = 0; i < pairs.size(); i++)
    {
        pair<int, int> minMax;
        minMax = FindMinMax(pairs[i].first);
        char desiredChar = pairs[i].first.back();
        int occurences = CountOccurences(desiredChar, pairs[i].second);
        if (occurences >= minMax.first && occurences <= minMax.second)
        {
            validPasswords++;
        }
    }
    return validPasswords;
}


pair<int, int> FindMinMax(string policy)
{
    size_t pos = policy.find('-');
    size_t end = policy.find(' ');
    pair<int, int> myPair;
    myPair.first = stoi(policy.substr(0, pos));
    myPair.second = stoi(policy.substr(pos + 1, end));
    return myPair;
}


int CountOccurences(char myChar, string password)
{
    int count = 0;
    for (unsigned int i = 0; i < password.size(); i++)
    {
        if (password[i] == myChar) count++;
    }
    return count;
}


int FindValidPasswordsPart2(vector<pair<string, string>> pairs)
{
    int validPasswords = 0;

    for (unsigned int i = 0; i < pairs.size(); i++)
    {
        pair<int, int> minMax;
        minMax = FindMinMax(pairs[i].first);
        char desiredChar = pairs[i].first.back();
        if ((pairs[i].second[minMax.first + 1] == desiredChar)
                != (pairs[i].second[minMax.second + 1] == desiredChar))
        {
            validPasswords++;
        }
    }
    return validPasswords;
}


#endif // DAY2_H
