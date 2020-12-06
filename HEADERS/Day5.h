#ifndef DAY5_H
#define DAY5_H


#include "Day3.h"


#include <cmath>
#include <utility>
#include <string>
#include <vector>


using std::ceil;
using std::floor;
using std::pair;
using std::pow;
using std::stoi;
using std::string;
using std::vector;


const int ROWDIGITS = 7;
const int COLUMNDIGITS = 3;


vector<string> GetTickets(string fileName)
{
    vector<string> Tickets = GetTrees(fileName);
    return Tickets;
}

string GetBinaryString(string input, char lower, char upper)
{
    string binaryString;
    for(unsigned int i = 0; i < input.length(); i++)
    {
        if(input[i] == lower) { binaryString.append("0"); }
        else if (input[i] == upper) { binaryString.append("1"); }
    }
    return binaryString;
}

int BinaryStringToInt(string input)
{
    return stoi(input, nullptr, 2);
}

int GetRow(string ticketRow)
{
    return BinaryStringToInt(GetBinaryString(ticketRow, 'F', 'B'));
}

int GetColumn(string ticketColumn)
{
    return BinaryStringToInt(GetBinaryString(ticketColumn, 'L', 'R'));
}

pair<int,int> GetSeat(string ticket)
{
    string row = ticket.substr(0, ROWDIGITS);
    string column = ticket.substr(ROWDIGITS, COLUMNDIGITS);
    return pair<int, int>(GetRow(row), GetColumn(column));
}

int GetSeatID(string ticket)
{
    pair<int, int> seat = GetSeat(ticket);
    return((seat.first * 8) + seat.second);
}

int GetMaxSeatID(vector<string> tickets)
{
    int maxID = -1;
    for (unsigned int i = 0; i < tickets.size(); i++)
    {
        int seatID = GetSeatID(tickets[i]);
        if (seatID > maxID) { maxID = seatID; }
    }
    return maxID;
}

#endif // DAY5_H
