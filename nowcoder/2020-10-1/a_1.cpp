#include <iostream>
using namespace std;

char colors[400001];

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> colors[i];

    int res = 0;
    int l = 0, r = N - 1;
    while (r - l > 0)
    {
        if (colors[l] == colors[r])
        {
            l++;
            r--;
        }
        else
        {
            l++;
            res++;
        }
    }

    cout << res << endl;

    return 0;
}