#include <iostream>

using namespace std;

typedef long long ll;
const int maxn = 2000000;
const int maxt = 70;
int a[maxn];

// cnta[i]:
// count of chicken whose life remain i
// (age & 1 == 0)
int cnta[maxt + 1];

// cntb[i]:
// count of chicken whose life remain i
// (age & 1 == 1)
int cntb[maxt + 1];

ll m, p;

ll solve(ll ca, ll cb)
{
    ll res = ca + cb;

    ll loop = (m - 1) / 2;

    for (ll i = 1; i <= loop; i++)
    {
        res -= cnta[2 * i];
        ca -= cnta[2 * i];
        res += ca;
        ca += ca;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;

    // ca: count of age & 1 == 0
    // cb: count of age & 1 == 1
    ll ca = 0, cb = 0;
    for (int i = 0; i < n; i++)
    {
        int age;
        cin >> age;
        if (age & 1)
            cb++;
        else
            ca++;
        a[i] = age;
    }

    int t;
    cin >> t >> m >> p;

    for (int i = 0; i < n; i++)
    {
        if (a[i] & 1)
            cntb[t - a[i]]++;
        else
            cnta[t - a[i]]++;
    }

    cout << solve(ca, cb);

    return 0;
}