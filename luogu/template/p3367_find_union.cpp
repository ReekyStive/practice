#include <iostream>

using namespace std;
const int MAX_N = 10002;
int par[MAX_N];

void init(int n)
{
    for(int i = 1; i <= n; i++)
        par[i] = i;
}

int find(int node)
{
    if (node == par[node])
        return node;
    else
        return par[node] = find(par[node]);
}

void unite(int a, int b)
{
    if (find(a) == find(b))
        return;
    else
        par[a] = find(b);
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m, x, y, type;
    cin >> n >> m;
    init(n);

    for (int i = 0; i < m; i++)
    {
        cin >> type >> x >> y;
        if (type == 1)
            unite(x, y);
        else
        {
            if (find(x) == find(y))
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
    }
    
    return 0;
}