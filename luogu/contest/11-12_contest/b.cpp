#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
ll inf = 100000000;

// a * a square need m bricks:
// m = (a + 1) * a * 2
// so:
// a = -1 + (4 + 8 * m) ^ 0.5 / 4
// m walls can build a * a square
inline ll cnt(ll m)
{
    return -1 + pow((4 + 8 * m), 0.5) / 4;
}

ll solve(ll m)
{
    ll a = cnt(m);
    ll res = a * a;
    m -= (a + 1) * a * 2;

    m--;
    if (m <= 0)
        return res;

    if (m >= 2 * a)
    {
        res += a;
        m -= 2 * a;

        m--;
        if (m <= 0)
            return res;
    }

    res += m / 2;
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll m;
        cin >> m;
        cout << solve(m) << endl;
    }
    return 0;
}