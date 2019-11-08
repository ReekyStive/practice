#include <iostream>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double res = (a + b + c) / 3;

    if (res < 60)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}