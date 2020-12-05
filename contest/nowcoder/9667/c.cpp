#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long a = n / 3;
    long long b = n % 3;

    long long x = ceil((double)(a - b - 1) / 4.0);
    a -= x;
    b += 3 * x;

    cout << a + b << endl;
    return 0;
}