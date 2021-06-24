#include <iostream>

using namespace std;

int main()
{
    int a, res;
    cin >> res;
    for (int i = 0; i < 3; i++)
    {
        cin >> a;
        if (a > res)
            res = a;
    }
    cout << res << endl;
}