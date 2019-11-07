#include <iostream>
#include <string>

using namespace std;

const string correct = "CORRECT";
const string small = "TOO_SMALL";
const string big = "TOO_BIG";
const string wrong = "WRONG_ANSWER";

void solve()
{
    int a, b, n;
    cin >> a >> b >> n;

    while (n--)
    {
        int q = a - (a - b) / 2;
        cout << q << endl;

        string tip;
        cin >> tip;

        if (tip == wrong || tip == correct)
            break;

        if (tip == small)
            a = q;

        if (tip == big)
            b = q;
    }

    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}