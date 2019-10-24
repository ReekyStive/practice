#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 2147483647;
const int max_v = 100000;

typedef pair<int, int> P;

struct Edge {
    int to;
    int cost;
};

vector<Edge> G[max_v];

int d[max_v];

void dijkstra(int v, int s)
{
    for (int i = 0; i < v; i++)
        d[i] = INF;
    d[s] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(0, s));

    while (!pq.empty()) {
        P cp = pq.top();
        pq.pop();

        int cv = cp.second;

        if (d[cv] < cp.first)
            continue;

        for (int i = 0; i < (int)G[cv].size(); i++) {
            Edge ed = G[cv][i];
            if (d[ed.to] > d[cv] + ed.cost) {
                d[ed.to] = d[cv] + ed.cost;
                pq.push(P(ed.cost, ed.to));
            }
        }
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

    for (int i = 0; i < v; i++)
        cout << d[i] << " ";
    cout << endl;

    return 0;
}
