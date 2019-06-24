#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 101;

int time[maxn];
int value[maxn];
int mem[maxn];

int dp(int i, int t)
{
    if (i < 0 || t < time[i])
        return 0;
    if (mem[i] != 0)
        return mem[i] - 1;

    mem[i] = max(dp(i - 1, t), dp(i - 1, t - time[i]) + value[i]) + 1;
    return mem[i] - 1;
}

int main()
{
    int t, m;
    cin >> t >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> time[i] >> value[i];
    }

    cout << dp(m - 1, t) << endl;

    return 0;
}
