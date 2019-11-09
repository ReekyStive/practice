#include <iostream>

using namespace std;

typedef long long ll;
const int maxn = 1000000;
ll a[maxn - 1];

// sum for a[i] in [l, r)
ll sum(int l, int r)
{
    ll res = 0;
    for (int i = l; i < r; i++)
        res += a[i];
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;

    if (k >= n - 1)
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < n - 1; i++)
        cin >> a[i];

    ll maxx = 0;
    for (int i = 0; i < n - k; i++)
        maxx = max(maxx, sum(i, i + k));

    ll res = sum(0, n - 1) - maxx;
    cout << res << endl;

    return 0;
}