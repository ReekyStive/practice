#include <iostream>

using namespace std;

const int MAX = 5000000;
bool not_prim[MAX * 20 + 1];
int x[20];

void prim(int max)
{
    for (int i = 3; i <= max / 3 + 1; i += 2)
    {
        if (not_prim[i])
            continue;
        for (int j = 3; j * i <= max; j += 2)
            not_prim[j * i] = true;
    }
}

bool is_prim(int n)
{
    if (n <= 3)
        return true;
    if (n % 2 == 0)
        return false;
    
    return !not_prim[n];
}

int solve(int pos, int remain, int sum)
{
    if (remain == 0)
        return is_prim(sum);
    if (remain > pos + 1)
        return 0;
    if (pos == 0)
        return is_prim(sum + x[0]);
    
    int count = 0;

    count += solve(pos - 1, remain, sum);
    count += solve(pos - 1, remain - 1, sum + x[pos]);

    return count;
}

int main()
{
    int n, k, count = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> x[i];

    prim(MAX * n);

    cout << solve(n - 1, k, 0) << endl;

    return 0;
}
