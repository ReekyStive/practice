#include <iostream>

using namespace std;

int main()
{
    int n, v, m, a;
    cin >> n >> v >> m >> a;

    int res = 0;
    while (n > m)
    {
        res += v * m;
        v += a;
        n -= m;
    }
    res += v * n;
    cout << res << endl;

    return 0;
}
