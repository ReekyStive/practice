#include <iostream>
using namespace std;

int dp[100001];
int spend[10000], value[10000];

int main()
{
    int t, m;
    cin >> t >> m;
    for (int i = 0; i < m; i++)
        cin >> spend[i] >> value[i];
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j <= t; j++)
        {
            if (j >= spend[i])
                dp[j] = max(dp[j], dp[j - spend[i]] + value[i]);
        }
    cout << dp[t];
    return 0;
}