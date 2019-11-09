#include <iostream>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> tri;

const int mod = 998244353;
const int maxn = 100000;
int a[maxn];
map<tri, ll> mem;

ll sum(int k, int l, int r)
{
    if (mem[tri(k, pair(l, r))] > 0)
        return mem[tri(k, pair(l, r))];

    ll res = 0;

    if (k == 1)
    {
        for (int i = l; i <= r; i++)
        {
            res += a[i - 1];
            res %= mod;
        }
        return res;
    }

    for (int i = l; i <= r; i++)
    {
        for (int j = i; j <= r; j++)
        {
            res += sum(k - 1, i, j);
            res %= mod;
        }
    }

    if (mem[tri(k, pair(l, r))] == 0)
        mem[tri(k, pair(l, r))] = res;

    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        cout << sum(k, 1, i) << " ";

    cout << endl;

    return 0;
}