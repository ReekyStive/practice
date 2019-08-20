// This is WRONG code (best answer), but CAN NOT solve the original problem.

#include <iostream>
#include <vector>

using namespace std;

struct Pos
{
    int x, y, count;
};

vector<Pos> peanuts;
bool used[400];

int dfs(int cur, int remain)
{
    if (peanuts[cur].y > remain)
        return 0;
    
    used[cur] = true;
    int max_count = 0;
    for (int i = 0; i < peanuts.size(); i++)
    {
        if (used[i])
            continue;
        max_count = max(max_count, dfs(i, remain - abs(peanuts[i].x - peanuts[cur].x) - abs(peanuts[i].y - peanuts[cur].y) - 1));
    }
    used[cur] = false;

    return peanuts[cur].count + max_count;
}

int main()
{
    int M, N, K;
    cin >> M >> N >> K;

    Pos point;
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> point.count;
            if (point.count > 0)
            {
                point.y = i;
                point.x = j;
                peanuts.push_back(point);
            }
        }
    }

    if (peanuts.size() == 0)
        cout << "0" << endl;
    else
    {
        int max_count = 0;
        for (int i = 0; i < peanuts.size(); i++)
        {
            used[i] = true;
            max_count = (max(max_count, dfs(i, K - peanuts[i].y - 1)));
            used[i] = false;
        }
        cout << max_count << endl;
    }
    
    return 0;
}
