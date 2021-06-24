#include <iostream>

using namespace std;

int h[7];
bool dat[31];

int day_of_month(int year, int month)
{
    if (month == 2)
    {
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
            {
                return 29;
            }
        }
        else
        {
            return 28;
        }
    }
    else
    {
        if (month == 1 ||
            month == 3 ||
            month == 5 ||
            month == 7 ||
            month == 8 ||
            month == 10 ||
            month == 12)
            return 31;
        else
            return 30;
    }
}

int calc(int days, int k)
{
    int res = 0;
    for (int i = 0; i < days; i++)
    {
        if (dat[i])
            res += h[(i + k) % 7];
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);

    for (int i = 0; i < 31; i++)
        dat[i] = false;

    int a, b;
    cin >> a >> b;

    for (int i = 0; i < 7; i++)
        cin >> h[i];
    
    int days = day_of_month(a, b);
    for (int i = 0; i < days; i++)
        cin >> dat[i];

    int res = calc(days, 0);
    for (int i = 1; i < 7; i++)
    {
        int tmp = calc(days, i);
        if (tmp < res)
            res = tmp;
    }

    cout << res << endl;

    return 0;
}