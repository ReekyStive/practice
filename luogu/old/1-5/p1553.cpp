#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

enum
{
    Integer = '\0',
    Decimal = '.',
    Fraction = '/',
    Percentage = '%'
};

int main()
{
    string ss, part1, part2;
    char temp, type = Integer;
    
    getline(cin, ss);
    istringstream sstream(ss);

    while (sstream >> temp)
    {
        switch (temp)
        {
            case Decimal:
                type = Decimal;
                break;
            case Fraction:
                type = Fraction;
                break;
            case Percentage:
                type = Percentage;
                break;
        }
        if (type != Integer)
            break;

        part1 += temp;
    }

    reverse(part1.begin(), part1.end());

    if (type != Integer)
    {
        while (sstream >> temp)
        {
            part2 += temp;
        }

        reverse(part2.begin(), part2.end());
    }

    while (part1[0] == '0' && part1.size() > 1)
        part1.erase(0, 1);
    
    if (type == Decimal)
        while (part2[part2.size() - 1] == '0' && part2.size() > 1)
            part2.erase(part2.size() - 1, 1);
    else
        while (part2[0] == '0' && part2.size() > 1)
            part2.erase(0, 1); 

    cout << part1 << type << part2;


    return 0;
}
