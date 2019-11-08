#include <iostream>

using namespace std;
typedef long long ll;

bool is(ll n)
{
    ll a, b;
    b = n % 10;
    while (b == n % 10 && n > 0)
    {
        n /= 10;
    }
    a = n % 10;
    while (a == n % 10 && n > 0)
    {
        n /= 10;
    }
    if (a != 0 && n == 0)
        return true;
    return false;
}

ll solve(ll n)
{
    ll i = 1;
    while (true)
    {
        if (is(n * i))
            return n * i;
        i++;
    }
    return -1;
}

int main()
{
    ll n;

    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        cout << n << ": ";
        cout << solve(n) << endl;
    }

    return 0;
}