#include <iostream>

using namespace std;

const int MAX_N = 20000;
bool not_prim[MAX_N + 1];

void gen_prim(int n)
{
    for (int i = 3; i <= n / 3 + 1; i++)
    {
        if (not_prim[i])
            continue;
        for (int j = 3; i * j <= n; j++)
            not_prim[i * j] = true;
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

int main()
{
    int n;
    cin >> n;
    gen_prim(n);

    int k;
    for (int i = 2; i <= n - 4; i++)
    {
        if (!is_prim(i))
            continue;
        
        for (int j = 2; j <= n - i - 2; j++)
        {
            if (!is_prim(j))
                continue;
            
            k = n - i - j;
            if (is_prim(k))
            {
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
    return 0;
}
