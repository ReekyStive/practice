#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<string, int> m;
void init_m()
{
    m[string("JAN")] = 1;
    m[string("FEB")] = 2;
    m[string("MAR")] = 3;
    m[string("APR")] = 4;
    m[string("MAY")] = 5;
    m[string("JUN")] = 6;
    m[string("JUL")] = 7;
    m[string("AUG")] = 8;
    m[string("SEP")] = 9;
    m[string("OCT")] = 10;
    m[string("NOV")] = 11;
    m[string("DEC")] = 12;
}

int days[12] =
{
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int get_month_days(int year, int month)
{
    if (year == 1582)
    {
        if (month == 10)
            return 21;
    }

    if (year < 1582)
    {
        if (year % 4 == 0)
        {
            if (month == 2)
                return 29;
            else
                return days[month - 1];
        }
        else
            return days[month - 1];
    }

    if (month != 2)
        return days[month - 1];
    
    // month == 2
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return 29;
            else
                return 28;
        }
        else
            return 29;
    }
    else
        return 28;
}

int get_year_days(int year)
{
    if (year == 1582)
        return 355;
    
    if (year < 1582)
    {
        if (year % 4 == 0)
            return 366;
        else
            return 365;
    }

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return 366;
            else
                return 365;
        }
        else
            return 366;
    }
    else
        return 365;
}

int main()
{
    init_m();

    int day, month, year;
    cin >> day;
    string s;
    for (int i = 0; i < 3; i++)
        s.push_back(cin.get());
    month = m[s];
    cin >> year;

    int sum = 0;
    for (int i = 1; i < year; i++)
        sum += get_year_days(i);

    for (int i = 1; i < month; i++)
        sum += get_month_days(year, i);
    
    sum += day - 1;

    cout << sum << endl;
    return 0;
}