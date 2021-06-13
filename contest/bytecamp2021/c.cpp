// Wrong

#include <iostream>

using namespace std;

int ans[10] = {-1, 1, 4, 5};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n <= 3)
            cout << ans[n] << endl;
        else
            cout << n * 2 << endl;
    }
    return 0;
}
