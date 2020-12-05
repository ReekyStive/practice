#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 2e5 + 1;
int par[max_n];
int height[max_n];

void init_node(int n)
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        height[i] = 1;
    }
}

int find(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    int root_x = find(x);
    int root_y = find(y);
    if (root_x == root_y)
        return;

    if (height[root_x] < height[root_y])
    {
        par[root_x] = root_y;
    }
    else
    {
        par[root_y] = root_x;
        if (height[root_x] == height[root_y])
            height[root_x]++;
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

struct edge
{
    int from;
    int to;
    int cost;
    bool operator<(const edge right)
    {
        if (this->cost < right.cost)
            return true;
        else
            return false;
    }
};

edge edges[max_n];

int main()
{
    int n, m;
    cin >> n >> m;

    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    init_node(n);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    }
    sort(edges, edges + m);

    int i = 0;
    int cnt = 0;
    int cost = 0;
    while (cnt < n - 1)
    {
        if (i == m)
        {
            cout << -1 << endl;
            return 0;
        }
        if (same(edges[i].from, edges[i].to))
        {
            i++;
            continue;
        }
        unite(edges[i].from, edges[i].to);
        cost += edges[i].cost;
        i++;
        cnt++;
    }

    cout << cost << endl;

    return 0;
}