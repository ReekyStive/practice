#include <iostream>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

ll fact[1000001];

void init(int n)
{
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;
}

ll qpow(ll x, ll n, ll p)
{
    x %= p;
    ll res = 1;
    while (n != 0)
    {
        if (n & 1)
            res = res * x % p;
        n >>= 1;
        x = x * x % p;
    }
    return res;
}

ll inv(ll x, ll p)
{
    return qpow(x, p - 2, p);
}

ll combination(ll n, ll m)
{
    ll ans = fact[n];
    ans = ans * inv(fact[n - m], mod) % mod;
    ans = ans * inv(fact[m], mod) % mod;
    return ans;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    init(n);

    ll ming = 1;
    ll maxg = n / k;
    ll res = 0;

    for (ll i = ming; i <= maxg; i++)
    {
        res += combination(n - (k - 1) * i - 1, i - 1) % mod;
        res %= mod;
    }
    cout << res << endl;

    return 0;
}