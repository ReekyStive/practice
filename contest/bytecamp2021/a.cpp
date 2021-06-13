// Wrong Algorithm

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 1;
int a[maxn];
int dp[maxn][2];

int get_p(int x)
{
    x++;
    return x / 2 - 1;
}

int get_l(int x)
{
    x++;
    return 2 * x - 1;
}

int get_r(int x)
{
    x++;
    return 2 * x;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    dp[0][0] = 0;
    dp[0][1] = a[0];

    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        int l = get_l(cur);
        int r = get_r(cur);
        if (l < n)
        {
            q.push(l);
            dp[l][0] = max(dp[cur][0], dp[cur][1]);
            dp[l][1] = max(dp[l][0], dp[cur][0] + a[l]);
        }
        if (r < n)
        {
            q.push(r);
            dp[r][0] = max(dp[cur][0], dp[cur][1]);
            dp[r][1] = max(dp[r][0], dp[cur][0] + a[r]);
        }
    }

    int res = 0;
    for (int i = n - 1; get_l(i) < n || get_r(i) < n; i--)
    {
        // TODO
    }

    return 0;
}
