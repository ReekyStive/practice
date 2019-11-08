#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long res = n * (n + 1) / 2;
    cout << res << endl;

    return 0;
}