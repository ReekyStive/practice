#include <iostream>

using namespace std;

struct Edge {
    int from;
    int to;
    int cost;
};

const int INF = 2147483647;
const int max_e = 500000;
const int max_v = 10000;
Edge edges[max_e];
int d[max_v];

void bellman_ford(int v, int e, int s)
{
    for (int i = 0; i < v; i++)
        d[i] = INF;

    d[s] = 0;

    while (true) {
        bool update = false;

        for (int i = 0; i < e; i++) {
            Edge e = edges[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }

        if (!update)
            break;
    }
}

int main()
{
    int v, e, s;
    cin >> v >> e >> s;
    s--;

    for (int i = 0; i < e; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
        edges[i].from--;
        edges[i].to--;
    }

    bellman_ford(v, e, s);

    for (int i = 0; i < v; i++)
        cout << d[i] << " ";

    cout << endl;

    return 0;
}
