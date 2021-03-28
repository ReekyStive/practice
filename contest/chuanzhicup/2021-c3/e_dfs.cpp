#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100000;
const int maxm = 100000;

int w[maxn];
int c[maxm];
int used[maxn];

int n, m;

int find_person(int price)
{
    for (int i = 0; i < n; i++)
    {
        if (w[i] >= price && !used[i])
            return i;
    }
    return -1;
}

int solve(int pos)
{
    if (pos >= m)
        return 0;
    if (find_person(c[pos]) == -1)
        return 0;

    int person_pos = find_person(c[pos]);
    used[person_pos] = 1;
    int buy = solve(pos + 1) + 1;
    used[person_pos] = 0;

    int not_buy = solve(pos + 1);
    return max(buy, not_buy);
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < m; i++)
        cin >> c[i];

    sort(w, w + n);
    sort(c, c + m);

    int res = solve(0);
    cout << res << endl;

    return 0;
}
