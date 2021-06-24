#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 25;
const int maxak = 30000;
int rp[maxn];
int rpp[maxn];
int ack[maxn][maxak];

int dp(int ac, int ak)
{
    if (ak < rp[ac] || ac < 0)
        return 0;
    if (ack[ac][ak] != 0)
        return ack[ac][ak];
    return ack[ac][ak] = max(rp[ac] * rpp[ac] + dp(ac - 1, ak - rp[ac]), dp(ac - 1, ak));
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
        cin >> rp[i] >> rpp[i];

    cout << dp(m - 1, n) << endl;

    return 0;
}
