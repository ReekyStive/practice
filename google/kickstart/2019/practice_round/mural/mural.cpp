#include <iostream>

using namespace std;

const int kMaxN = 5000000;
int section[kMaxN];

void solve()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        section[i] = c - '0';
    }

    return;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }

    return 0;
}