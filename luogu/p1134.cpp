#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    long long n, ans = 1;
    cin >> n;

    for (int i = n; i >= 1; i--)
    {
        ans *= i;
        while (ans % 10 == 0)
            ans /= 10;
        ans %= 10000000;
    }
    ans %= 10;
    cout << ans << endl;

    system("pause");

    return 0;
}