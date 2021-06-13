// Wrong Algorithm

#include <iostream>
#include <queue>

using namespace std;

const int maxn = 101;
int g[maxn][maxn];
int c[maxn];
int used[maxn];
int n, m;

int bfs(int s)
{
    for (int i = 0; i < n; i++)
        used[i] = 0;

    queue<int> q;
    q.push(s);
    used[s] = 1;
    int found = c[s];
    int depth = 1;
    while (!q.empty())
    {
        if (found == m)
            return depth;

        queue<int> temp;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < n; i++)
            {
                if (g[cur][i] > 0 && !used[i])
                {
                    temp.push(i);
                    used[i] = 1;
                    if (c[i])
                        found++;
                }
            }
        }
        depth++;
        q = temp;
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    if (n == 0 || m == 0)
    {
        cout << "0" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; i++)
        c[i] = 0;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        c[x] = 1;
    }

    int res = 109;
    for (int i = 0; i < n; i++)
    {
        if (c[i] > 0)
        {
            int cur = bfs(i);
            res = min(res, cur);
        }
    }
    cout << res << endl;

    return 0;
}
