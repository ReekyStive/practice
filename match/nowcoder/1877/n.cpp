#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int res;
    res = n / 12;
    res = res * 4 + 2;

    cout << res << endl;

    return 0;
}