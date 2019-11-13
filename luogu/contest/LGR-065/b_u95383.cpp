#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

const int inf = 1 << 30;

struct Edge
{
    int from;
    int to;
    int val;
};

const int maxn = 10000;
const int maxm = 2 * maxn;

int dis[maxn][maxn];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dis[i][j] = inf;

    for (int i = 0; i < n; i++)
        dis[i][i] = 0;

    for (int i = 0; i < n; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        dis[x - 1][y - 1] = v;
    }

    // solve()

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << dis[x][y] << endl;
    }

    return 0;
}