#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 100000;
int mem[MAX];
const int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int qwq[10] = {8, 9, 6, 9, 29, 39, 38, 65, 88, 128};
int n, max_num;

int get_costs(int n)
{
    if (n == 0)
        return cost[0];
    
    if (mem[n] > 0)
        return mem[n] - 1;
    
    int costs = 0;
    while (n != 0)
    {
        costs += cost[n % 10];
        n /= 10;
    }

    return (mem[n] = costs + 1) - 1;
}

int solve(int a, int b)
{
    int remain = n - get_costs(a) - get_costs(b);
    if (remain < 2)
        return 0;
    if (remain == get_costs(a + b))
        return 1;

    return 0;
}

int main()
{
    cin >> n;
    n -= 4;
    max_num = pow(10, ceil(n / 4));

    int count = 0;

    if (n >= 6)
    {
        if (n + 4 >= 15)
            count = qwq[n + 4 - 15];
        else
        {
            // a == b
            for (int i = 0; i <= max_num; i++)
                count += solve(i, i);
            
            // a != b: a + b == b + a
            for (int i = 0; i <= max_num; i++)
                for (int j = i + 1; j <= max_num; j++)
                    count += solve(i, j) * 2;
        }
    }
    
    cout << count << endl;

    return 0;
}
