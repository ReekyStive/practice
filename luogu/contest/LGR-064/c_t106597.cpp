#include <iostream>
#include <deque>

const int maxn = 1000000;
const int maxm = 33333;

using namespace std;

int s[maxn];
deque<int> t;

bool is(int l)
{
    for (int i = 1; i <= l; i++)
    {
        if (t[t.size() - l + i - 1] == s[i - 1])
            return false;
    }
    return true;
}

int solve()
{
    int res = 0;
    for (int i = 1; i <= t.size(); i++)
    {
        if (is(i))
            res++;
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> s[i];

    bool opt;
    int ch;
    for (int i = 0; i < m; i++)
    {
        cin >> opt >> ch;
        if (opt)
            t.push_front(ch);
        else
            t.push_back(ch);

        cout << solve() << endl;
    }

    return 0;
}