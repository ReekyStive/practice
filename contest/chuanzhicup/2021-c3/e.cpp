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

    int res = 0;
    for (int i = 0; i < m; i++)
    {
        int person_pos = find_person(c[i]);
        if (person_pos == -1)
            break;
        used[person_pos] = 1;
        res++;
    }

    cout << res << endl;

    return 0;
}
