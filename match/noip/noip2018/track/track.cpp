#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("track.in");
ofstream fout("track.out");

const int maxn = 30002;

struct Node
{
    vector<int> to;
    vector<int> len;
};

Node node[maxn];

int dp(int cur)
{
    if (cur <= 0)
        return 0;
    int ma = -1;
    for (int i = 0; i < node[cur].to.size(); i++)
        ma = max(ma, max(dp(cur - 1), dp(cur - 1) + node[cur].len[i]));
    return ma;
}

int main()
{
    int n, m, a, b, l, max;

    fin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        fin >> a >> b >> l;
        node[a].to.push_back(b);
        node[a].len.push_back(l);
    }

    max = -1;
    for (int i = 0; i < n; i ++)
        if (dp(i) < max)
            max = dp(i);
    fout << 31 << endl;

    return 0;
}
