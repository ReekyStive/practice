#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;

const int inf = __INT_MAX__ / 4;
const int inf_out = __INT_MAX__;
const int nul = -1;

struct pair_t
{
    int to;
    int length;
    bool operator<(pair_t p);
};

struct node
{
    int key;
    vector<pair_t> edge;
};

bool pair_t::operator<(pair_t p)
{
    return this->length < p.length;
}

vector<int> dijkstra(vector<node> g, int s);

int main()
{
    vector<node> g;
    vector<int> dis;
    int n, m, s, f;
    pair_t p;

    cin >> n >> m >> s;
    g.resize(n);

    for (int i = 0; i < n; i++)
    {
        g[i].key = i;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> f >> p.to >> p.length;
        if (p.to == p.length)
            continue;

        g[f].edge.push_back(p);
    }

    dis = dijkstra(g, s);

    for (int i = 0; i < n; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}

vector<int> dijkstra(vector<node> g, int s)
{
    vector<int> dis;
    vector<int> parent;
    priority_queue<pair_t> q;
    set<int> seen;
    pair_t p;
    int cur, len, fnt;

    dis.resize(g.size());
    fill(dis.begin(), dis.end(), inf);
    dis[s] = 0;

    parent.resize(g.size());
    parent[s] = nul;
    p.to = s;
    p.length = 0;
    q.push(p);
    seen.insert(s);

    while (!q.empty())
    {
        p = q.top();
        q.pop();

        for (int i = 0; i < g[f].to.size(); i++)
        {
            cur = g[fro][i].begin()->first;
            if (seen.find(cur) == seen.end())
            {
                q.push(g[fro][i].begin()->first);
                seen.insert(cur);
            }
        }
    }

    return dis;
}
