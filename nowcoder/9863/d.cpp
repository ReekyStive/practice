#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if ((n - 1) % 2 == 0)
        cout << n << endl;
    else
        cout << -1 << endl;
    return 0;
}