#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long sb, sp, b, p, k;
    long long ans = 1;
    cin >> b >> p >> k;
    sb = b;
    sp = p;

    while (p > 0)
    {
        if (p & 1)
        {
            ans *= b;
            ans %= k;
        }

        b *= b;
        b %= k;
        p >>= 1;
    }
    cout << sb << "^" << sp << " mod " << k << "=" << ans << endl;
    system("pause");
    return 0;
}