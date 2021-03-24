#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 10;
int v[maxn];
int w[maxn];
int d[maxn][30000 + 10];

int dp(int i, int n)
{
    if (d[i][n] != 0) return d[i][n] - 1;
    if (n <= 0 || i == 0) return 0;
    d[i][n] = max(dp(i - 1, n), dp(i - 1, n - v[i]) + (n >= v[i] ? v[i] * w[i] : 0)) + 1;
    return d[i][n] - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m, ans;

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> v[i] >> w[i];

    ans = dp(m, n);
    cout << ans << endl;

    return 0;
}
