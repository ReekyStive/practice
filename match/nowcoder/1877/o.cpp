#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    if (a < b)
        swap(a, b);
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int main()
{
    ll a, b;

    cin >> a >> b;
    cout << gcd(a, b) + lcm(a, b) << endl;

    return 0;
}