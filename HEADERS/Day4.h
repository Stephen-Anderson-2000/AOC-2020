#ifndef DAY4_H
#define DAY4_H


#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <sstream>
#include <string>
#include <vector>


using std::fstream;
using std::getline;
using std::istream_iterator;
using std::stoi;
using std::string;
using std::stringstream;
using std::vector;


vector<string> GetCredentials(string fileName)
{
    fstream myFile(fileName);
    vector<string> credentials;
    if(myFile)
    {
        string line;
        string fullCredential;
        while (getline(myFile, line))
        {
            if (line.size() > 0) { fullCredential += line + ' '; }
            else
            {
                credentials.push_back(fullCredential);
                fullCredential = "";
            }
        }
        if (fullCredential != "") { credentials.push_back(fullCredential); }
    }
    return credentials;
}

vector<string> GenerateRequiredFields()
{
    vector<string> requiredFields;
    requiredFields.push_back("byr");
    requiredFields.push_back("iyr");
    requiredFields.push_back("eyr");
    requiredFields.push_back("hgt");
    requiredFields.push_back("hcl");
    requiredFields.push_back("ecl");
    requiredFields.push_back("pid");
    return requiredFields;
}

vector<string> ParseCredential(string credential)
{
    stringstream ssCredential(credential);
    istream_iterator<string> begin(ssCredential);
    istream_iterator<string> end;
    vector<string> vecCredential(begin, end);
    return vecCredential;
}

bool ContainsRequiredFields(string credential, vector<string> requiredFields)
{
    for (unsigned int i = 0; i < requiredFields.size(); i++)
    {
        if (credential.find(requiredFields[i]) == string::npos) { return false; }
    }
    return true;
}

int GetYear(string field)
{
    if (field.length() == 4)
    {
        try { return std::stoi(field); }
        catch (...) { return -1; }
    }
    return -1;
}

bool BirthYearIsValid(string field)
{
    int birthYear = GetYear(field);
    if (birthYear != -1 && birthYear >= 1920 && birthYear <= 2002) { return true; }
    return false;
}

bool IssueYearIsValid(string field)
{
    int issueYear = GetYear(field);
    if (issueYear != -1 && issueYear >= 2010 && issueYear <= 2020) { return true; }
    return false;
}

bool ExpirationYearIsValid(string field)
{
    int expireYear = GetYear(field);
    if (expireYear != -1 && expireYear >= 2020 && expireYear <= 2030) { return true; }
    return false;
}
bool HeightIsValid(string field)
{
    string units;
    int height = -1;
    if (field.find("cm") != string::npos) { units = "cm"; }
    else if (field.find("in") != string::npos) { units = "in"; }
    else { return false; }
    try { height = stoi(field.substr(0, field.find(units))); }
    catch (...) { return false; }
    if (units == "cm" && height >= 150 && height <= 193) { return true; }
    else if (units == "in" && height >= 59 && height <= 76) { return true; }
    return false;
}

bool HairIsValid(string field)
{
    std::regex hairRegex("^#([0-9a-f]){6}");
    return std::regex_match(field, hairRegex);
}

bool EyeIsValid(string field)
{
    const string validColours[7] = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
    for (int i = 0; i < 7; i++) { if (field.find(validColours[i]) != string::npos) { return true; }}
    return false;
}

bool PassportIsValid(string field)
{
    if (field.length() == 9)
    {
        try
        {
            stoi(field);
            return true;
        }
        catch (...) { return false; }
    }
    return false;
}

bool AllFieldsValid(string credential)
{
    bool allValid = false;
    vector<string> vecCredential = ParseCredential(credential);
    for (unsigned int i = 0; i < vecCredential.size(); i++)
    {
        string fieldName = vecCredential[i].substr(0, credential.find(':'));
        string fieldValue = vecCredential[i].substr(credential.find(':') + 1);
        if (fieldName.find("byr") != string::npos) { allValid = BirthYearIsValid(fieldValue); }
        else if (fieldName.find("iyr") != string::npos) { allValid = IssueYearIsValid(fieldValue); }
        else if (fieldName.find("eyr") != string::npos) { allValid = ExpirationYearIsValid(fieldValue); }
        else if (fieldName.find("hgt") != string::npos) { allValid = HeightIsValid(fieldValue); }
        else if (fieldName.find("hcl") != string::npos) { allValid = HairIsValid(fieldValue); }
        else if (fieldName.find("ecl") != string::npos) { allValid = EyeIsValid(fieldValue); }
        else if (fieldName.find("pid") != string::npos) { allValid = PassportIsValid(fieldValue); }
        else if (fieldName.find("cid") != string::npos) { allValid = true; }
        if (allValid == false)
        {
            return false;
        }
    }
    return allValid;
}

int CountContainsRequiredFields(vector<string> credentials, vector<string> requiredFields)
{
    int validCount = 0;
    for (unsigned int i = 0; i < credentials.size(); i++)
    {
        if (ContainsRequiredFields(credentials[i], requiredFields)) { validCount++; }
    }
    return validCount;
}

int CountValidCredentials(vector<string> credentials, vector<string> requiredFields)
{
    int validCount = 0;
    for (unsigned int i = 0; i < credentials.size(); i++)
    {
        if (ContainsRequiredFields(credentials[i], requiredFields) && AllFieldsValid(credentials[i])) { validCount++; }
    }
    return validCount;
}

#endif // DAY4_H
