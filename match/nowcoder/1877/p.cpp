#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int res = 0;
    int i = 0;
    while (n != 0)
    {
        if ((n % 10) % 2 == 1)
            res += pow(10, i);
        n /= 10;
        i++;
    }

    cout << res << endl;

    return 0;
}