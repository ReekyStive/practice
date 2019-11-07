#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b, c;
    int big = 0;
    // 1 for a, 2 for b

    cin >> a >> b;

    if (a.length() == b.length())
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] > b[i])
            {
                big = 1;
                break;
            }
            if (a[i] < b[i])
            {
                big = 2;
                break;
            }
        }
    else if (a.length() > b.length())
        big = 1;
    else
        big = 2;

    if (big == 0)
    {
        cout << "0";
        return 0;
    }

    if (big == 2)
        swap(a, b);

    c = a;

    b.insert(0, a.length() - b.length(), '0');

    for (int i = c.length() - 1; i >= 0; i--)
    {
        c[i] = c[i] - b[i] + '0';
        if (i > 0 && c[i] < '0')
            c[i] += 10, c[i - 1] -= 1;
    }

    while (c[0] == '0')
        c.erase(0, 1);

    if (big == 2)
        cout << "-";

    cout << c;

    return 0;
}