#include <iostream>
#include <map>

using namespace std;

typedef long long ll;
map<ll, ll> mem;

ll solve(ll n)
{
    if (n <= 1)
        return 0;

    if (mem[n] > 0)
        return mem[n];

    ll a = n / 2;
    ll b = n - a;

    mem[n] = solve(a) + solve(b) + a + b - 1;
    return mem[n];
}

int main()
{
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}