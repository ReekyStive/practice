#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

inline int max3(int a, int b, int c)
{
    return max(a, max(b, c));
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    double m = (double)max3(a + b, b, c);
    m /= (double)(max3(a, b + c, c) + max3(a, b, b + c));

    cout << fixed << setprecision(2);
    cout << m << endl;

    return 0;
}