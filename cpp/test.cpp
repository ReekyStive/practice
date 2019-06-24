#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define maxn 1025

using namespace std;

vector<int> e[maxn];
bool vis[maxn];
int n, m;

void dfs(int s)
{
    if (vis[s])
        return;

    //    cout << "Now we are at point " << s << endl;
    cout << s << " -> ";
    vis[s] = 1;

    for (int i = 0; i < e[s].size(); i++)
        dfs(e[s][i]);

    return;
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = 1;

    while (!q.empty())
    {
        for (int i = 0; i < e[q.front()].size(); i++)
        {
            if (vis[e[q.front()][i]])
                continue;

            vis[e[q.front()][i]] = 1;
            q.push(e[q.front()][i]);
        }
        cout << q.front() << " -> ";
        q.pop();
    }
}

void resetting()
{
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < maxn; i++)
        e[i].clear();
}

int main()
{
    bool con = 1;
    while (con)
    {
        resetting();
        int a, b, s;
        scanf("%d %d %d", &n, &m, &s);

        while (m--)
        {
            scanf("%d %d", &a, &b);
            e[a].push_back(b);
            e[b].push_back(a);
        }

        bfs(s);
        cout << "out\nContinue?(Y/N) ";
        char co;
        cin >> co;
        if (co == 'N')
            con = 0;
    }
}