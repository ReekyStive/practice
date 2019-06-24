#include <iostream>
#include <string>
#include <cstdio>
#include <windows.h>
using namespace std;

const int maxn = 100000 + 10;
bool d[maxn];
string job[maxn];

int main()
{
    int n, m, ti, tii, cur = 0;
    string ts;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> ti >> ts;
        if (ti)
            d[i] = !d[i];
        job[i] = ts;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> ti >> tii;
        if (ti ^ d[cur])
            cur += tii;
        else
            cur -= tii;
        while (cur < 0)
            cur += n;
        cur %= n
    }

    cout << job[cur] << endl;
    system("pause");

    return 0;
}