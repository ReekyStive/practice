#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    bool stat[26];
    while (t--)
    {
        for (int i = 0; i < 26; i++)
            stat[i] = false;

        int n;
        cin >> n;
        char c1, c2;
        cin >> c1;
        stat[c1 - 'A'] = true;

        bool suspicious = false;
        for (int i = 1; i < n; i++)
        {
            cin >> c2;
            if (c2 == c1)
                continue;

            c1 = c2;
            if (stat[c1 - 'A'])
                suspicious = true;
            stat[c1 - 'A'] = true;
        }

        if (suspicious)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
