#include <iostream>
using namespace std;

int mem[1000];

int solve(int n)
{
    if (mem[n] > 0)
        return mem[n];
    
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

    mem[n] = result;
    return result;
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}