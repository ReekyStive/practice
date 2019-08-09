#include <iostream>
#include <algorithm>

using namespace std;

int a[10001], b[10001], g[10001], k[10001];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> g[i] >> k[i];

    int x, y;
    cin >> x >> y;

    for (int i = n; i >= 1; i--)
    {
        if (a[i] > x || b[i] > y)
            continue;
        
        if (a[i] + g[i] >= x && b[i] + k[i] >= y)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    
    return 0;
}
