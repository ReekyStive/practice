#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string res;
    while (n != 0)
    {
        res += n % 6 + '0';
        n /= 6;
    }

    reverse(res.begin(), res.end());
    cout << res << endl;

    return 0;
}