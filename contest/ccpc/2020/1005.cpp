#include <iostream>
#include <vector>

using namespace std;

int calc_cnt(long long n)
{
    int res = 0;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            n /= i;
            res++;
            i = 1;
        }
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    long long len;
    int times, res = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> len;
        times = calc_cnt(len);
        res += times;
        res %= 2;
    }

    if (res % 2 == 0)
        cout << 'L' << endl;
    else
        cout << 'W' << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}