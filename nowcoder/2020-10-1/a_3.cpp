#include <iostream>
using namespace std;

char colors[400001];

bool check(int l, int r)
{
    int res = true;
    while (r - l > 0)
    {
        if (colors[l] == colors[r])
        {
            l++;
            r--;
        }
        else
        {
            res = false;
            break;
        }
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> colors[i];

    int res = 0;
    int l = N - 1, r = N - 1;
    for (int i = 0; i <= r; i++)
    {
        if (check(i, r))
        {
            l = i;
            break;
        }
    }

    cout << l << endl;

    return 0;
}