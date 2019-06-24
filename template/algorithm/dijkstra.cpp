#include <iostream>
#include <algorithm>
using namespace std;

const int intmax = __INT_MAX__;
const int inf = intmax / 4;

void dijkstra(int **g, int *d, const int maxn, int s);

int main()
{
    ios::sync_with_stdio(false);

    const int maxn = 10e4;
    int n, m, s, a, b, val, g[maxn][maxn], d[maxn] = {inf};

    cin >> n >> m >> s;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                g[i][j] = 0;
            else
                g[i][j] = inf;
        }
    }

    d[s] = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> val;
        if (a != b)
            g[a][b] = val;
    }

    dijkstra(g, d, maxn, s);

    return 0;
}

void dijkstra(int **g, int *d, const int maxn, int s)
{
    ;
}
