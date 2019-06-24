#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 10002;
int s[maxn][maxn];
int rp[maxn][maxn];
int n;

int dp(int r, int c)
{
    if (r > n || c < 1)
        return 0;
    if (rp[r][c] != 0)
        return rp[r][c] - 1;
    
    rp[r][c] = s[r][c] + max(dp(r + 1, c), dp(r + 1, c + 1)) + 1;
    return rp[r][c] - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cin >> s[i][j];
    }

    cout << dp(1, 1) << endl;
    system("pause");
    return 0;
}