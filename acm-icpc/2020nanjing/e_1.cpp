// Wrong Answer

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int mx, my;
        cin >> mx >> my >> s;
        int u = 0, d = 0, l = 0, r = 0;
        for (auto i : s)
        {
            if (i == 'U')
                u++;
            if (i == 'D')
                d++;
            if (i == 'L')
                l++;
            if (i == 'R')
                r++;
        }

        if (
            mx == 0 && my == 0 ||         // mine at start
            mx == r - l && my == u - d || // mine at goal
            my == 0 && u == 0 && d == 0 && mx < max(0, r - l) && mx > min(0, r - l) ||
            mx == 0 && l == 0 && r == 0 && my < max(0, u - d) && my > min(0, u - d))
        {
            cout << "Impossible" << endl;
            continue;
        }

        string ans;
        if (mx == 0)
        {
            for (int i = 0; i < r; i++)
                ans += 'R';
            for (int i = 0; i < l; i++)
                ans += 'L';

            if (r - l == mx)
            {
                if (!ans.empty())
                {
                    char tmp_c = *(ans.end() - 1);
                    ans.pop_back();
                    for (int i = 0; i < u; i++)
                        ans += 'U';
                    for (int i = 0; i < d; i++)
                        ans += 'D';
                    ans += tmp_c;
                }
                else
                {
                    if (my > 0)
                    {
                        for (int i = 0; i < d; i++)
                            ans += 'D';
                        for (int i = 0; i < u; i++)
                            ans += 'U';
                    }
                    else
                    {
                        for (int i = 0; i < u; i++)
                            ans += 'U';
                        for (int i = 0; i < d; i++)
                            ans += 'D';
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < u; i++)
                ans += 'U';
            for (int i = 0; i < d; i++)
                ans += 'D';

            if (u - d == my)
            {
                if (!ans.empty())
                {
                    char tmp_c = *(ans.end() - 1);
                    ans.pop_back();
                    for (int i = 0; i < r; i++)
                        ans += 'R';
                    for (int i = 0; i < l; i++)
                        ans += 'L';
                    ans += tmp_c;
                }
                else
                {
                    if (mx > 0)
                    {
                        for (int i = 0; i < l; i++)
                            ans += 'L';
                        for (int i = 0; i < r; i++)
                            ans += 'R';
                    }
                    else
                    {
                        for (int i = 0; i < r; i++)
                            ans += 'R';
                        for (int i = 0; i < l; i++)
                            ans += 'L';
                    }
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
