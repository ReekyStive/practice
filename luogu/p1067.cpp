#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n;

    if (n == 1)
    {
        cin >> m;
        cout << m;
    }
    else
    {
        for (int i = n; i >= 0; i--)
        {
            cin >> m;
            if (m == 0)
                continue;
            
            if (m == 1)
                cout << '+';
            else if (m != 1)
            {
                if (m == -1)
                    cout << '-';
                else
                {
                    if (m > 0 && i != n)
                        cout << '+';
                    cout << m;
                }
            }

            if (i >= 0)
            {
                cout << 'x';
                if (i >= 1)
                    cout << '^' << i;
            }
        }
    }

    return 0;
}
