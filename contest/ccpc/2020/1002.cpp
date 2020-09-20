#include <iostream>
using namespace std;

long long dis[10000000001];
bool selected[10000000001];

int gcd(int a, int b)
{
    int c;
    if (a < b)
    {
        c = b;
        b = a;
        a = c;
    }

    while (b != 0)
    {
        c = b;
        b = a % b;
        a = c;
    }

    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;
        int res = 0;
        for (int i = 2; i <= n; i++)
        {
            res += i;
            res %= k;
        }
        cout << res << endl;
    }
    return 0;
}