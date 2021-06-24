#include <iostream>

using namespace std;

// fraction a / b
struct node
{
    double val;
    long long a;
    long long b;
};

long long gcd(long long a, long long b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    if (a < b)
    {
        long long temp = a;
        a = b;
        b = temp;
    }
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long my_pow(int x)
{
    return 1LL << x;
}

node f(int a, int b, int x)
{
    node res;
    res.a = a * x + b;
    res.b = my_pow(x);
    res.val = (double)res.a / res.b;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int m = 0; m < t; m++)
    {
        int a, b, n;
        cin >> a >> b >> n;
        node res = f(a, b, 0);
        for (int i = 1; i <= n; i++)
        {
            node cur = f(a, b, i);
            if (cur.val > res.val)
                res = cur;
        }

        long long c = gcd(res.a, res.b);
        res.a /= c;
        res.b /= c;

        if (res.b < 0)
        {
            res.b = -res.b;
            res.a = -res.a;
        }
        if (res.b == 1)
            cout << res.a << endl;
        else
            cout << res.a << '/' << res.b << endl;
    }

    return 0;
}