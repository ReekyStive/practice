#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
const ll mod = 1000000007;

inline ll lowbit(ll x) { return x & (~x + 1); }

// calc a^n quickly
ll fbow(ll a, ll n)
{
    ll res = 1;
    ll tmp = a;
    while (n != 0)
    {
        if (n & 1)
        {
            res *= tmp;
            // res %= mod;
        }
        tmp *= tmp;
        // tmp %= mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    ll n;
    cin >> n;

    ll res = 0;
    ll end = fbow(2, n);

    for (ll i = 0; i < end; i++)
    {
        ll lb = lowbit(i + 1);
        ll fb = fbow(lb, end - i);
        ll lg = log2(fb);

        // cout << "i = " << i << ", lb = " << lb;
        // cout << ", fb = " << fb << ", lg = " << lg << endl;
        res += lg;
        res %= mod;
    }

    cout << res << endl;

    return 0;
}