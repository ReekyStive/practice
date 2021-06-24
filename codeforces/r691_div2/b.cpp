#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long res;
    if (n % 2 == 0)
        res = (n / 2 + 1) * (n / 2 + 1);
    else
        res = ((n + 1) / 2) * ((n + 3) / 2) * 2;
    cout << res << endl;
    return 0;
}