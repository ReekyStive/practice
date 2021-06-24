#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int k;
    cin >> k;

    int sq = sqrt(k);
    int remain = k - sq * sq;
    // int _cnt = 0;

    for (int i = 0; i < sq; i++)
        cout << "(";

    for (int i = 0; i < sq - 1; i++)
    {
        int cur = sq - i;
        if (cur <= remain)
        {
            cout << "(";
            remain -= cur;
            // _cnt++;
        }
        cout << ")";
    }

    for (int i = 0; i < remain; i++)
        cout << "(";

    cout << ")" << endl;

    // cout << "count: " << _cnt + sq + sq + remain << endl;

    return 0;
}