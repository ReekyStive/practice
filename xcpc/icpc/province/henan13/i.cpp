#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int trans[8] = {1, 4, 7, 2, 5, 8, 3, 6};

bool del(vector<int> &d, int n)
{
    auto it = find(d.begin(), d.end(), n);
    if (it != d.end())
    {
        d.erase(it);
        return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    cin.get();
    while (t--)
    {
        string s;
        getline(cin, s);
        vector<int> d;
        for (int i = 0; i < 8; i++)
        {
            if (s[i] == '1')
                d.push_back(trans[i]);
        }
        if (d.size() == 0)
        {
            cout << "Yes" << endl;
            continue;
        }

        int cen = d[0];
        int cur = cen;
        while (del(d, cur))
        {
            cur++;
            if (cur > 8)
                cur -= 8;
        }
        cur = (cen - 2 + 8) % 8 + 1;
        while (del(d, cur))
        {
            cur--;
            if (cur < 1)
                cur += 8;
        }
        if (d.size() == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
