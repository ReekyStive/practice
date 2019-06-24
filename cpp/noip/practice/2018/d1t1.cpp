#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int d[maxn];
int n;

int fbegin()
{
    for (int i = 0; i < n; i++)
    {
        if (d[i] > 0)
            return i;
    }
    return -1;
}

int fend(int be)
{
    for (int i = be; i < n; i++)
    {
        if (d[i] == 0)
            return i - 1;
    }
    return n - 1;
}

void bk(int a, int b, int deep)
{
    for (int i = a; i <= b; i++)
    {
        d[i] -= deep;
    }
}

int fm(int a, int b)
{
    int m = d[a];
    for (int i = a + 1; i <= b; i++)
    {
        if (d[i] < m)
            m = d[i];
    }
    return m;
}

int main()
{
    int b, e, deep;
    long long ans = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> d[i];
    
    b = fbegin();
    while (b != -1)
    {
        e = fend(b);
        deep = fm(b, e);
        bk(b, e, deep);
        ans += deep;

        b = fbegin();
    }

    cout << ans << endl;

    return 0;
}