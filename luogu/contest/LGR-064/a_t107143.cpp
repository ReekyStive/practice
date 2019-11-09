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

    int l = 0, r = k - 1;
    ll maxx = 0;
    for (int i = 0; i < k; i++)
        maxx += a[i];

    ll tmp = maxx;

    while (true)
    {
        r++;
        if (r >= n)
            break;

        tmp -= a[l];
        tmp += a[r];

        l++;

        if (tmp > maxx)
            maxx = tmp;
    }

    ll res = sum(0, n - 1) - maxx;
    cout << res << endl;

    return 0;
}