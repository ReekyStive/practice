#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 102;
int rp[maxn];
int ak[10000][100];
int n;

int dp(int m, int i)
{
    if (ak[m][i] != 0)
        return ak[m][i] - 1;
    if (m == 0)
        return 1;
    if (i < 0)
        return 0;
        
    ak[m][i] = dp(m - rp[i], i - 1) + dp(m, i - 1) + 1;
    return ak[m][i] - 1;
}

int main()
{
    int m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> rp[i];

    cout << dp(m, n - 1) << endl;

    system("pause");
    return 0;
}