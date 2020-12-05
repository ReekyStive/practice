#include <iostream>

using namespace std;

const int max_n = 2e5;
const int max_i = 2e5;
int data[max_n];
bool used[max_i + 1];

int solve(int score, int cur)
{
    if (cur < 0)
        return score;

    if (used[data[cur]] == false)
    {
        bool stat_left, stat_right;
        if (data[cur] - 1 >= 0)
        {
            stat_left = used[data[cur] - 1];
            used[data[cur] - 1] = true;
        }
        if (data[cur] + 1 >= 0)
        {
            stat_right = used[data[cur] + 1];
            used[data[cur] + 1] = true;
        }

        int select = solve(score + data[cur], cur - 1);

        if (data[cur] - 1 >= 0)
        {
            used[data[cur] - 1] = stat_left;
        }
        if (data[cur] + 1 >= 0)
        {
            used[data[cur] + 1] = stat_right;
        }

        int unselecte = solve(score, cur - 1);
        return max(select, unselecte);
    }
    else
    {
        return solve(score, cur - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> data[i];

    cout << solve(0, n - 1) << endl;

    return 0;
}