#include <iostream>

using namespace std;

const int kMaxN = 100;
int a[kMaxN];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int x;
    cin >> x;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (x == a[i])
            count++;
    }

    cout << count << endl;

    return 0;
}