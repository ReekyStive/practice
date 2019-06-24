#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int S[maxn + 10];
int R[maxn + 10];
vector<vector<int> > a;

int main()
{
    int T, n, Q, len, ai, m;
    cin >> n >> T >> Q;
    for (int i = 0; i < T; i++)
        cin >> S[i];
    for (int i = 0; i < n; i++)
    {
        cin >> len;
        vector<int> temp;
        for (int j = 0; j < len; j++)
        {
            cin >> ai;
            temp.push_back(ai);
        }
        a.push_back(temp);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> R[i];
    return 0;
}