#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t, n, m, k, p, a, b;
    vector<vector<int> > prk;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> m >> k >> p;

        prk.clear();
        prk.resize(n);
        for (int i = 0; i < n; i++)
            prk[i].resize(n);
        
        for (int i = 0; i < n; i++)
            fill(prk[i].begin(), prk[i].end(), __INT_MAX__);
        
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            cin >> prk[a][b];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << prk[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
