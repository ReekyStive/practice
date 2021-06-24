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
        int q = (a + 1 + b) / 2;
        cout << q << endl;

        string tip;
        cin >> tip;

        if (tip == wrong || tip == correct)
            break;

        if (tip == small)
            a = q + 1;

        if (tip == big)
            b = q - 1;
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