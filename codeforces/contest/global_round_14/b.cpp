#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1e-8;

bool is(long long n)
{
    return fabs(pow(floor(sqrt(n) + eps), 2) - n) < eps;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;
        if (x % 2 == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            bool res1 = is(x / 2);
            bool res2 = false;
            if (x % 4 == 0)
                res2 = is(x / 4);

            if (res1 || res2)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
