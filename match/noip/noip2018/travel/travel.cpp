#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;

ifstream fin("travel.in");
ofstream fout("travel.out");

const int maxn = 5002;

priority_queue<int> edge[maxn];
bool seen[maxn];

int main()
{
    int n, m, temp, tempb;
    stack<int> stk;
    fin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        fin >> temp >> tempb;
        edge[temp].push(tempb);
        edge[tempb].push(temp);
    }

    stk.push(1);
    seen[1] = true;
    while (!stk.empty())
    {
        temp = 0;
        temp = stk.top();
        stk.pop();
        fout << temp << " ";

        while (!edge[temp].empty())
        {
            tempb = edge[temp].top();
            edge[temp].pop();
            if (!seen[tempb])
            {
                stk.push(tempb);
                seen[tempb] = true;
            }
        }
    }

    fout << endl;

    fin.close();
    fout.close();

    return 0;
}
