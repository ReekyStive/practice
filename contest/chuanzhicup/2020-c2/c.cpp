#include <iostream>
#include <algorithm>

using namespace std;

struct item
{
    int val;
    int t;
    int no;
};
const int max_n = 500001;
item dat[max_n];

bool cmp(item l, item r)
{
    if (l.val == r.val)
    {
        if (l.t == r.t)
            return l.no < r.no;
        else
            return l.t > r.t;
    }
    else
    {
        return l.val > r.val;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int t, k;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> k;
        dat[i].val = t * k;
        dat[i].t = t;
        dat[i].no = i + 1;
    }

    sort(dat, dat + n, cmp);

    for (int i = 0; i < n; i++)
    {
        cout << dat[i].no << " ";
    }
    cout << endl;

    return 0;
}