#include <iostream>
using namespace std;

int solve(int n)
{
    if (n < 2)
    {
        if (n == 1)
            return 1;
        else
            return 0;
    }

    int result = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        result += solve(i);
    }
    result++;

    return result;
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
    system("pause");
    return 0;
}