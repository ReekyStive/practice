#include <iostream>
#include <cmath>

using namespace std;

int x[20];

bool is_prim(int n)
{
    if (n <= 3)
        return true;
    if (n % 2 == 0)
        return false;

    int end = sqrt(n) + 1;

    for (int i = 3; i <= end; i++)
        if (n % i == 0)
            return false;

    return true;
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

    cout << solve(n - 1, k, 0) << endl;

    return 0;
}
