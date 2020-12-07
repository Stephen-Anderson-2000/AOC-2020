#ifndef DAY6_H
#define DAY6_H


#include <algorithm>
#include <fstream>
#include <string>
#include <vector>


#include "Day4.h"


using std::count;
using std::fstream;
using std::string;
using std::vector;


vector<string> GetQuestionnaireResponses(string fileName)
{
    vector<string> responses;
    responses = GetCredentials(fileName);
    return responses;
}

unsigned int CountYesAnswers(string response)
{
    string encounteredQuestions;
    for (unsigned int i = 0; i < response.length(); i++)
    {
        if (isalpha(response[i]) && (encounteredQuestions.find(response[i]) == string::npos))
        {
            encounteredQuestions += response[i];
        }
    }
    return (encounteredQuestions.length());
}

int GetTotalYesAnswers(vector<string> responses)
{
    int total = 0;
    for (unsigned int i = 0; i < responses.size(); i++)
    {
        total += CountYesAnswers(responses[i]);
    }
    return total;
}

int CountUnanimous(string response)
{
    int total = 0;
    int numPeople = count(response.begin(), response.end(), ' ');
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (count(response.begin(), response.end(), c) == numPeople) { total++; }
    }
    return total;
}

int GetUnanimousAnswers(vector<string> responses)
{
    int total = 0;
    for (unsigned int i = 0; i < responses.size(); i++)
    {
        total += CountUnanimous(responses[i]);
    }
    return total;
}

#endif // DAY6_H
