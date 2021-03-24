#include <iostream>
#include <iomanip>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<set<int>> sets(n);

    for (int i = 0; i < n; i++)
    {
        int count;
        cin >> count;
        for (int j = 0; j < count; j++)
        {
            int temp;
            cin >> temp;
            sets[i].insert(temp);
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        int total_size = sets[a].size();
        int a_size = sets[a].size();
        int b_size = sets[b].size();

        for (auto it = sets[b].begin(); it != sets[b].end(); it++)
            if (sets[a].count(*it) == 0)
                total_size++;

        double res = (double)(a_size + b_size - total_size) / (double)total_size;
        cout << fixed << setprecision(2) << res * 100.0 << '%' << endl;
    }

    return 0;
}
