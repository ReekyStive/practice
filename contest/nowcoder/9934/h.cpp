#include <iostream>

const int max_n = 100000;
int dat[max_n];

using namespace std;

int ma(int n)
{
    int res = dat[0];
    for (int i = 1; i < n; i++)
    {
        if (dat[i] > res)
            res = dat[i];
    }
    return res;
}

int mi(int n)
{
    int res = dat[0];
    for (int i = 1; i < n; i++)
    {
        if (dat[i] < res)
            res = dat[i];
    }
    return res;
}

long long sum(int n)
{
    long long res = 0;
    for (int i = 0; i < n; i++)
        res += dat[i];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> dat[i];

        long long ak_max = mi(n);
        long long ak_min = m - (m * n - sum(n));
        if (ak_min < 0)
            ak_min = 0;

        long long zero_max = m - ma(n);
        long long zero_min = m - sum(n);
        if (zero_min < 0)
            zero_min = 0;

        cout << ak_min << ' ' << ak_max << endl;
        cout << zero_min << ' ' << zero_max << endl;
    }
    return 0;
}