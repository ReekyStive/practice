// NOT Accepted: Time Limit Exceed

// #include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 200000;
const int mod = 998244353;
int a[maxn + 1];
int b[maxn + 1];

int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long calc(int n, int k)
{
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 > k)
            break;
        for (int j = 0; j < n; j++)
        {
            if (i + j + 2 > k)
                break;
            if (i + j + 2 + gcd(i + 1, j + 1) == k)
            {
                res += (a[i] % mod) * (b[j] % mod) % mod;
                res %= mod;
            }
        }
    }
    return res;
}

int main()
{
    // ios::sync_with_stdio(false);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    for (int i = 1; i <= 3 * n; i++)
    {
        printf("%lld ", calc(n, i));
    }
    printf("\n");

    return 0;
}
