// TLE

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 1;
int a[maxn];
int used[maxn];
int n;

int get_p(int x)
{
    x++;
    return x / 2 - 1;
}

int dfs(int cur, int val)
{
    if (cur == n)
        return val;
    if (get_p(cur) < 0 || used[get_p(cur)] == 0)
    {
        used[cur] = 1;
        int r1 = dfs(cur + 1, val + a[cur]);
        used[cur] = 0;
        int r2 = dfs(cur + 1, val);
        return max(r1, r2);
    }
    return dfs(cur + 1, val);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << dfs(0, 0) << endl;

    return 0;
}
