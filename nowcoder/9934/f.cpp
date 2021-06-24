#include <iostream>

using namespace std;

int mi(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int res = 0;

    int temp;

    temp = mi(a, b);
    a -= temp;
    b -= temp;
    res += temp;

    temp = mi(a, c);
    a -= temp;
    c -= temp;
    res += temp;

    temp = c / 2;
    c -= temp * 2;
    res += temp;

    cout << res << endl;

    return 0;
}