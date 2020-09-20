#include <iostream>
#include <string>
using namespace std;

string s;

bool equal(int al, int ar, int bl, int br)
{
    if (ar - al < 0 && br - bl < 0)
        return true;
    if (br - bl != ar - al)
        return false;
    int len = ar - al;
    for (int i = 0; i <= len; i++)
    {
        if (s[al + i] != s[bl + i])
            return false;
    }
    return true;
}

int lborder(int i)
{
    int res = -1;
    for (int j = i - 1; j >= 0; j--)
    {
        if (equal(1, j, i - j + 1, i))
        {
            res = j;
            break;
        }
    }
    return res;
}

int d(int i)
{
    if (i == 0)
        return 0;
    else
        return d(lborder(i) + 1);
}

int main()
{
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        s.clear();
        cin.get();
        getline(cin, s);
        int n = s.length();
        int res = -1, di = -1;
        for (int i = 0; i <= n; i++)
        {
            di = d(i);
            if (di > res)
                res = di;
        }
        cout << "Case #" << j << ": " << res << endl;
    }
    return 0;
}