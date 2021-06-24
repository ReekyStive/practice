#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef __int128_t lll;

void lllcin(lll &v)
{
    string tmp;
    cin >> tmp;
    v = 0;
    lll t = 1;

    for (int i = 0; i < tmp.size(); i++)
    {
        v += t * (tmp[tmp.size() - 1 - i] - '0');
        t *= 10;
    }
}

void lllcout(lll v)
{
    string tmp;

    while (v != 0)
    {
        tmp.push_back(v % 10 + '0');
        v /= 10;
    }

    reverse(tmp.begin(), tmp.end());
    cout << tmp;
}

int main()
{
    lll a;
    lllcin(a);
    lllcout(a);
    cout << endl;
    return 0;
}