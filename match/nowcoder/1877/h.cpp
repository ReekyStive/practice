#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = 1;
        for (int j = 1; j <= i; j++)
            tmp *= j;
        res += tmp;
    }

    cout << res << endl;

    return 0;
}