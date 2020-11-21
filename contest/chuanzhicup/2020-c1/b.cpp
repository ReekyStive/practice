#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> c;

    for (long long i = 1; i < c; i++)
    {
        double sq = sqrt(c * c - i * i);
        if (fabs(sq - (double)(int)sq) < 1e-9)
        {
            a = i;
            b = sq;
            break;
        }
    }

    cout << a << ' ' << b << endl;

    return 0;
}