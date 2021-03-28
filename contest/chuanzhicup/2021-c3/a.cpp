#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    set<int> a;
    int n, m;
    cin >> n >> m;

    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.insert(temp);
    }

    int res = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        if (a.count(temp) > 0)
            res++;
    }

    cout << res << endl;

    return 0;
}
