#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int res;
    cin >> res;
    n--;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a > res)
            res = a;
    }

    cout << res << endl;

    return 0;
}