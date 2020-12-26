#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        double maxx = b;
        ll ans_a = b, ans_b = 1;
        for (int i = 1; i <= n; i++)
        {
            ll tmp1 = a * i + b;
            ll tmp2 = 1 << i;
            if (1.0 * tmp1 / tmp2 > maxx)
                maxx = 1.0 * tmp1 / tmp2, ans_a = tmp1, ans_b = tmp2;
        }
        ll k = __gcd(ans_a, ans_b);
        ans_a /= k, ans_b /= k;
        if (ans_b < 0)
            ans_b *= -1, ans_a *= -1;
        cout << ans_a;
        if (ans_b != 1)
            cout << "/" << ans_b;
        cout << endl;
    }
    return 0;
}