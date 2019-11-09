#include <iostream>

const int max_k = 10;
int a[max_k];

bool stay(int cur, int k)
{
    for(int i = 0; i < k; i++)
    {
        if (cur == a[i])
            return true;
    }
    return false;
}

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
        std::cin >> a[i];

    int cur = 0, cost = 0;

    while (cur < n)
    {
        if (stay(cur, k))
            m++;
        cur += m;
        cost++;
    }

    std::cout << cost << std::endl;

    return 0;
}