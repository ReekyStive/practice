#include <iostream>

using namespace std;

const long long mod = 1000000007;
const int max_n = 3000000;

long long po(long long a, int n)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res *= a;
            res %= mod;
        }
        n = n >> 1;
        a *= a;
        a %= mod;
    }
    return (int)(res % mod);
}

long long solve(int n)
{
    long long res = 0;

    for (int i = 1; i<= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            res += (i % mod) * po(i / j, j) % mod;
            res %= mod;
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    solve(n);

    // for (int i = 1000; i <= 1010; i++)
    //     cout << "n = " << i << ", result = " << solve(i) << endl;

    return 0;
}
