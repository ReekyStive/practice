#include <iostream>

using namespace std;

typedef long long ll;
const int mod = 998244353;
const int maxn = 100000;
int a[maxn];

ll sum(int k, int l, int r)
{
    ll res = 0;

    if (k == 1)
    {
        for (int i = l; i <= r; i++)
        {
            res += a[i - 1];
            res %= mod;
        }
        return res;
    }

    for (int i = l; i <= r; i++)
    {
        for (int j = i; j <= r; j++)
        {
            res += sum(k - 1, i, j);
            res %= mod;
        }
    }

    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        cout << sum(k, 1, i) << " ";

    cout << endl;

    return 0;
}