#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
    char cur;
    int win = 0, lose = 0, new_win = 0, new_lose = 0;
    ostringstream strout;

    while (cin >> cur, cur != 'E')
    {
        if (cur == 'W')
            win++, new_win++;
        else
            lose++, new_lose++;
        
        if ((win >= 11 || lose >= 11) && abs(win - lose) >= 2)
        {
            cout << win << ":" << lose << endl;
            win = 0;
            lose = 0;
        }

        if ((new_win >= 21 || new_lose >= 21) && abs(new_win - new_lose) >= 2)
        {
            strout << new_win << ":" << new_lose << endl;
            new_win = 0;
            new_lose = 0;
        }
    }

    cout << win << ":" << lose << endl;
    strout << new_win << ":" << new_lose << endl;
    cout << endl;

    cout << strout.str();

    return 0;
}
