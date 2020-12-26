#include <iostream>

using namespace std;

const int max_n = 200000;
int a[max_n], b[max_n];

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int a_max = 0, b_max = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] - a_max <= 0)
            continue;
        if (b[i] - b_max <= 0)
            continue;
        if (a[i] - a_max < b[i] - b_max)
            a_max = a[i];
        else if (a[i] - a_max > b[i] - b_max)
            b_max = b[i];
        else
        {
            if (a[i] > b[i])
                b_max = b[i];
            else
                a_max = a[i];
        }
    }
    cout << (long long)a_max + (long long)b_max << endl;

    return 0;
}