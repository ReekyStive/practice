#include <iostream>

using namespace std;
typedef long long ll;

const ll md = 1000000007;

ll k;

ll solve(int n, ll cur)
{
    if (n == 0)
        return cur % k == 0;

    ll res = 0;
    for (int i = 1; i <= 6; i++)
        res += solve(n - 1, cur * 10 + i);

    return res;
}

int main()
{
    int n;
    cin >> n >> k;

    ll res = solve(n, 0);
    cout << res;

    return 0;
}