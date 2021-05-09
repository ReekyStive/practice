#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    long long m, k;
    while (scanf("%lld %lld", &m, &k) != EOF)
    {
        long long ans;
        if (k <= (1 + m) * m / 2)
        {
            ans = ceil((sqrt(1 + 8 * k) - 1) / 2) + 1;
        }
        else
        {
            k -= (1 + m) * m / 2;
            ans = ceil(((2 * m - 1) - sqrt((2 * m - 1) * (2 * m - 1) - 8 * k)) / 2) + m + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
