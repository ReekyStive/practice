#include <iostream>

using namespace std;

int tree[8192];
int get_l(int n)
{
    return n * 2 + 1;
}
int get_r(int n)
{
    return n * 2 + 2;
}
int get_p(int n)
{
    return (n - 1) / 2;
}

int dfs(int cur)
{
    if (tree[cur] <= 1)
        return 1;
    int l = get_l(cur);
    int r = get_r(cur);
    return dfs(l) + dfs(r) + 1;
}

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        int pos = n - 2 + temp;

        tree[pos] = 1;
        int cur = pos;
        while (cur != 0)
        {
            cur = get_p(cur);
            tree[cur] += 1;
        }
    }

    cout << dfs(0) << endl;
    return 0;
}
