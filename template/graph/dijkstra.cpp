#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 2147483647;
const int max_v = 100000;

struct Edge {
    int to;
    int cost;
};

vector<Edge> G[max_v];

int d[max_v];
bool used[max_v];

void dijkstra(int v, int s)
{
    for (int i = 0; i < v; i++) {
        d[i] = INF;
        used[i] = false;
    }
    d[s] = 0;

    while (true) {
        int cv = -1;

        for (int i = 0; i < v; i++) {
            if (!used[i] && (cv == -1 || d[i] < d[cv]))
                cv = i;
        }

        if (cv == -1)
            break;
        used[cv] = true;

        vector<Edge>& ed = G[cv];
        for (int i = 0; i < (int)G[cv].size(); i++)
            d[ed[i].to] = min(d[ed[i].to], d[cv] + ed[i].cost);
    }
}

void show(int v)
{
    for (int i = 0; i < v; i++) {
        cout << "Node: " << i << endl;

        for (int j = 0; j < (int)G[i].size(); j++) {
            cout << "To: " << G[i][j].to << " ";
            cout << "Cost: " << G[i][j].cost << endl;
        }

        cout << endl;
    }
}

int main()
{
    int v, e, s;
    cin >> v >> e >> s;
    s--;

    int from, to, cost;
    Edge ed;

    for (int i = 0; i < e; i++) {
        cin >> from >> to >> cost;
        ed.to = --to;
        ed.cost = cost;
        G[--from].push_back(ed);
    }

    dijkstra(v, s);
    // show(v);

    for (int i = 0; i < v; i++)
        cout << d[i] << " ";
    cout << endl;

    return 0;
}
