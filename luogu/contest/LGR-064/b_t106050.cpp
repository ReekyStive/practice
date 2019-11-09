#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int res = 1;
    bool ta, tb;
    cin >> ta;
    tb = ta;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> tb;
        if (tb != ta)
        {
            ta = tb;
            res++;
        }
    }

    cout << res << endl;

    return 0;
}