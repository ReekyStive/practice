// Wrong Answer

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1000;
vector<int> v[maxn];

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        for (int i = 0; i < m; i++)
        {
            int from, to;
            scanf("%d %d", &from, &to);
            from--, to--;
            v[from].push_back(to);
            v[to].push_back(from);
        }

        while (true)
        {
            bool updated = false;
            for (int i = 0; i < n; i++)
            {
                if (v[i].size() == 1)
                {
                    int from = i, to = v[i][0];
                    v[from].erase(v[from].begin());
                    v[to].erase(find(v[to].begin(), v[to].end(), from));
                    updated = true;
                }
            }

            if (!updated)
                break;
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i].size() != 0)
                count++;
        }

        if (count != 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
