#include <iostream>
#include <windows.h>
using namespace std;

const int INF = 1 << 30;
const int MAX_N = 10001;
const int MAX_M = 500001;
int n, m;

struct edge_t
{
    int from, to, cost;
};

edge_t edge[MAX_M];
int d[MAX_N];

void bellman_ford(int s)
{
    bool update = true;
    for (int i = 0; i < n; i++)
        d[i] = INF;
    
    d[s] = 0;

    while(update)
    {
        update = false;
        for (int i = 0; i < m; i++)
        {
            if (d[edge[i].from] != INF && d[edge[i].to] > d[edge[i].from] + edge[i].cost)
            {
                d[edge[i].to] = d[edge[i].from] + edge[i].cost;
                update = true;
            }
        }
    }
}

int main()
{
    int s, f, g;
    cin >> n >> m >> s;
    s--;

    for (int i = 0; i < m; i++)
    {
        cin >> f >> g >> edge[i].cost;
        edge[i].from = f - 1;
        edge[i].to = g - 1;
    }
    
    bellman_ford(s);

    for (int i = 0; i < n; i++)
        cout << d[i] << " ";

    system("pause");
    return 0;
}