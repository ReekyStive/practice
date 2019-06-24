#include <iostream>
using namespace std;

int dp[101][1001];
int spend[100], value[100];

int main()
{
    int t, m;
    cin >> t >> m;
    for (int i = 0; i < m; i++)
        cin >> spend[i] >> value[i];
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j <= t; j++)
        {
            if (j < spend[i])
                dp[i + 1][j] = dp[i][j];
            else
                dp[i + 1][j] = max(dp[i][j], dp[i][j - spend[i]] + value[i]);
        }
    cout << dp[m][t];
    return 0;
}