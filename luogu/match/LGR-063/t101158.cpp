#include <iostream>

const int max_n = 300000;
int s[max_n];
bool sub[max_n];

int gcd(int a, int b)
{
    if (a < b)
        std::swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int comb(int n, int a)
{
    if (n - a < a)
        a = n - a;

    int res = 1;

    for(int i = n; i >= n - a + 1; i--)
        res *= i;

    for (int i = 1; i <= a; i++)
        res /= i;
    
    return res;
}

int calc(int n)
{
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        if (true)
            ;
    }
}

bool next(int cur)
{
    if (cur < 0)
        return false;
}

int main()
{
    int n, p;
    std::cin >> n >> p;

    for (int i = 0; i < n; i++)
        std::cin >> s[i];

    for (int i = 0; i < n; i++)
        sub[i] = false;

    long long res = 1;
    int counter = 0;

    if (n == 1)
        res = (s[0] = 1) %= p;

    std::cout << res << std::endl;

    return 0;
}