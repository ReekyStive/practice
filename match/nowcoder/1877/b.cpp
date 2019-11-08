#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double res = a + b + c;

    cout << fixed << setprecision(2);
    cout << res << " " << res / 3 << endl;

    return 0;
}