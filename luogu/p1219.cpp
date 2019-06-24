#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
const int maxn = 28;
int u[maxn];
int v[maxn];
int lx[maxn];
int rx[maxn];
int n;
int cnt = 0;
vector<vector<int> > ans;
vector<int> temp;

void get(int r, int c)
{
    lx[c + r - 1] = 1;
    rx[c - r + 2 + n] = 1;
    u[r] = 1;
    v[c] = 1;
}

void clear(int r, int c)
{
    lx[c + r - 1] = 0;
    rx[c - r + 2 + n] = 0;
    u[r] = 0;
    v[c] = 0;
}

bool find(int r, int c)
{
    return
    lx[c + r - 1] ||
    rx[c - r + 2 + n] ||
    u[r] ||
    v[c];
}

void dfs(int r, int c)
{
    temp[n - r] = c;
    if (r == 1)
    {
        if (!find(r, c))
        {
            cnt++;
            if (ans.size() < 3)
                ans.push_back(temp);
        }
        return;
    }
    if (!find(r, c))
    {
        get(r, c);
        for (int i = 1; i <= n; i++)
            dfs(r - 1, i);
        clear(r, c);
    }
}

int main()
{
    cin >> n;
    temp.resize(n);
    for (int i = 1; i <= n; i++)
        dfs(n, i);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << cnt << endl;
    return 0;
}
