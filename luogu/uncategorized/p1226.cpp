#include <iostream>
using namespace std;

typedef long long ll;
ll k;

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
            res %= k;
        }
        tmp *= tmp;
        tmp %= k;
        n >>= 1;
    }
    return res;
}

int main()
{
    ll b, p;
    cin >> b >> p >> k;

    cout << b << "^" << p << " mod " << k << "=" << fbow(b, p) % k << endl;

    return 0;
}