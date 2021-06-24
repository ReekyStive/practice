#include <iostream>
using namespace std;

int dp[1001];
int spend[100], value[100];

int main()
{
    int t, m;
    cin >> t >> m;
    for (int i = 0; i < m; i++)
        cin >> spend[i] >> value[i];
    
    for (int i = 0; i < m; i++)
        for (int j = t; j >= 0; j--)
        {
            if (j >= spend[i])
                dp[j] = max(dp[j], dp[j - spend[i]] + value[i]);
        }
    cout << dp[t];
    return 0;
}