// The result is Fib! f(n) = f(n - 1) + f(n - 2)

#include <iostream>

using namespace std;

const long long mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    n--;

    long long end_c = 1, end_y = 1;
    long long n_c, n_y;
    long long res = 0;

    while (n > 0)
    {
        n_c = end_y;
        n_y = end_c + end_y;

        end_c = n_c % mod;
        end_y = n_y % mod;

        n--;
    }
    res = (end_c + end_y) % mod;

    cout << res << endl;

    return 0;
}
