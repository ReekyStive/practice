#include <iostream>
#include <algorithm>

using namespace std;

int top[20001][20001];

int main()
{
    int n, a, b, g, k;
    cin >> n;

    int i;
    for (i = 1; i <= n; i++)
    {
        cin >> a >> b >> g >> k;

        for (int x = a; x <= a + g; x++)
            for (int y = b; y <= b + k; y++)
                top[x][y] = i;
    }

    cin >> a >> b;
    if (top[a][b] == 0)
        cout << -1 << endl;
    else
        cout << top[a][b] << endl;
    
    return 0;
}
