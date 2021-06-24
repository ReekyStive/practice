#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<long long, vector<int>> flowers;

long long solve(int s, int t)
{
    long long res = 0;

    for (auto &cur : flowers)
    {
        if (cur.second[0] > t || cur.second[cur.second.size() - 1] < s)
            continue;

        auto l = lower_bound(cur.second.begin(), cur.second.end(), s);
        auto r = upper_bound(cur.second.begin(), cur.second.end(), t) - 1;
        int len = r - l + 1;

        long long temp_res = len * cur.first;
        if (temp_res > res)
            res = temp_res;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;

        flowers[temp].push_back(i + 1);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int s, t;
        cin >> s >> t;
        cout << solve(s, t) << endl;
    }

    return 0;
}
