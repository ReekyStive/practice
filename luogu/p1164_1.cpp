#include <iostream>
#include <algorithm>
#include <windows.h>
using namespace std;

int dp[2][10001];
int a[100];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    
    dp[0][0] = 1;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j<= m; j++)
        {
            if (j < a[i])
                dp[(i + 1) & 1][j] = dp[i & 1][j];
            else
                dp[(i + 1) & 1][j] = dp[i & 1][j] + dp[i & 1][j - a[i]]; 
        }
    cout << dp[n & 1][m];
    system("pause");
    return 0;
}