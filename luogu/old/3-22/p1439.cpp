#include <iostream>

const int kMaxN = 100000;
int p1[kMaxN], p2[kMaxN];
int dp[2][kMaxN + 1];

int solve(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (p1[i - 1] == p2[j - 1])
                dp[i & 1][j] = dp[(i - 1) & 1][j - 1] + 1;
            else
                dp[i & 1][j] = std::max(dp[(i - 1) & 1][j], dp[i & 1][j - 1]);
        }
    }
    return dp[n & 1][n];
}

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
        std::cin >> p1[i];

    for (int i = 0; i < n; i++)
        std::cin >> p2[i];

    std::cout << solve(n) << std::endl;

    return 0;
}
