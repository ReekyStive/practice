#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 1;
int rp[maxn];
int rpp[maxn][maxn];
int r[maxn];

bool cmp (int a, int b)
{
    return rp[a] < rp[b];
}

int main()
{
    int n, ans = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> rp[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> rpp[i][j];
    
    for (int i = 0; i < n; i++)
        r[i] = i;
    sort(r, r + n, cmp);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans += rp[ r[i] ] * rpp[ r[i] ][ r[j] ];
        }
        for (int j = 0; j < n; j++)
            rpp[j][ r[i] ] = 0;
    }

    cout << ans << endl;
    
    system("pause");
    return 0;
}