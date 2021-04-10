#include <iostream>

using namespace std;

int main()
{
    int l, k;
    cin >> l >> k;
    if (l == 2)
    {
        if (k == 1 || k == 2 || k == 3)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
