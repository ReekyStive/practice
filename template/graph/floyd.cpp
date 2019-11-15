#include <iostream>

using namespace std;

const int inf = 1000000000;
const int maxn = 100;
int g[maxn][maxn];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = inf;

    for (int i = 0; i < n; i++)
        g[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        int a, b, v;
        cin >> a >> b >> v;
        g[a][b] = v;
        g[b][a] = v;
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }

    return 0;
}