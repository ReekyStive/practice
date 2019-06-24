#include <iostream>
using namespace std;

const int MAX_N = 10e6 + 1;
bool prim[MAX_N];

void gen(int max)
{
    for (int i = 3; i <= max; i += 2)
    {
        if (prim[i])
            continue;
        for (int j = 3; j * i <= max; j += 2)
        {
            prim[i * j] = true;
        }
    }
}

int main()
{
    int n, m, l, r, t;
    cin >> n >> m;
    gen(m);
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        if (l < 1 || r < 1 || l > m || r > m)
            cout << "Crossing the line" << endl;
        else
        {
            t = 0;
            for(int i = l; i <= r; i += 2)
            {
                if (!prim[i])
                    t++;
                if (i == l && l % 2 == 0)
                    i--;
            }
            cout << t << endl;
        }
    }
    
    return 0;
}