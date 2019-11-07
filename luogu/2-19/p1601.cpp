#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b;

    cin >> a >> b;

    if (a.length() < b.length())
        swap(a, b);

    a.insert(0, 1, '0');
    b.insert(0, a.length() - b.length(), '0');

    for (int i = a.length() - 1; i >= 0; i--)
    {
        a[i] = a[i] + b[i] - '0';
        if (a[i] > '0' + 9)
            a[i] -= 10, a[i - 1] += 1;
    }

    while (a[0] == '0' && a.length() > 1)
        a.erase(0, 1);

    cout << a;

    return 0;
}