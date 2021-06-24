#include <iostream>
#include <string>

using namespace std;

string s;

bool is(int start, int len)
{
    int end = start + len - 1;
    for (int i = 0; i < len / 2; i++)
    {
        int l = start + i;
        int r = end - i;
        if (s[l] != s[r])
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);

    getline(cin, s);
    int len = s.length();

    for (int i = len; i >= 2; i--)
    {
        for (int j = 0; j <= len - i; j++)
        {
            if (!is(j, i))
            {
                cout << i << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;
    return 0;

    return 0;
}