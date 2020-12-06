#ifndef DAY3_H
#define DAY3_H


#include <string>
#include <utility>
#include <vector>


using std::pair;
using std::string;
using std::vector;


vector<string> GetTrees(string fileName)
{
    fstream myFile(fileName);
    vector<string> lines;
    if(myFile)
    {
        string line;
        while (getline(myFile, line))
        {
            if (line.size() > 0)
            {
                lines.push_back(line);
            }
        }
        if (!line.empty())
        {
            lines.push_back(line);
        }
    }
    myFile.close();
    return lines;
}


int CountEncounteredTrees(vector<string> lines, int xIncrement = 1, int yIncrement = 1)
{
    unsigned int xOffset = 0;
    int trees = 0;
    for (unsigned int i = 0; i < lines.size(); i += yIncrement)
    {

        if(lines[i][xOffset] == '#')
        {
            trees++;
        }
        xOffset += xIncrement;
        if (xOffset >= lines[i].length())
        {
            xOffset -= lines[i].length();
        }
    }
    return trees;
}

long int CheckMultipleSlopes(vector<string> lines, vector<pair<int, int>> rules)
{
    vector<int> results;
    long int total = 1;
    for (unsigned int i = 0; i < rules.size(); i++)
    {
        results.push_back(CountEncounteredTrees(lines, rules[i].first, rules[i].second));
    }
    for (unsigned int i = 0; i < results.size(); i++)
    {
        total = total * results[i];
    }
    return total;
}

vector<pair<int, int>> CreateRules()
{
    vector<pair<int, int>> rules;
    rules.push_back(pair<int, int>(1,1));
    rules.push_back(pair<int, int>(3,1));
    rules.push_back(pair<int, int>(5,1));
    rules.push_back(pair<int, int>(7,1));
    rules.push_back(pair<int, int>(1,2));
    return rules;
}

#endif // DAY3_H
