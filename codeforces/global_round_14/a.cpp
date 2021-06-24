#include <iostream>
#include <algorithm>
using namespace std;

int a[101];

int mymax(int n)
{
    int res = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > res)
            res = a[i];
    }
    return res;
}

int sum(int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res += a[i];
    return res;
}

bool same(int n)
{
    for (int i = 1; i < n; i++)
        if (a[i] != a[0])
            return false;
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int m = mymax(n);
        if (m > x)
        {
            cout << "YES" << endl;
            int max_index = 0;

            while (a[max_index] != m)
                max_index++;

            cout << m << " ";

            for (int i = 0; i < n; i++)
                if (i != max_index)
                    cout << a[i] << " ";
            cout << endl;

            continue;
        }

        int s = sum(n);
        if (s == x)
        {
            cout << "NO" << endl;
            continue;
        }
        if (s < x)
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
            continue;
        }

        // s > x
        bool is_same = same(n);
        if (is_same)
        {
            if (x % a[0] == 0)
                cout << "NO" << endl;
        }
        else
        {
            int res = 0;
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {
                res += a[i];
                if (res == x)
                {
                    swap(a[i], a[i + 1]);
                    break;
                }
            }
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
    }
    return 0;
}
