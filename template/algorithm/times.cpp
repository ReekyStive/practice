#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string a, b, result;
    cin >> a >> b;

    if (a == "0" || b == "0")
    {
        cout << '0' << endl;
        return 0;
    }

    vector<long long> c(a.length() + b.length());
    fill(c.begin(), c.end(), 0);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < a.length(); i++)
        for (int j = 0; j < b.length(); j++)
            c[j + i] += (a[i] - '0' ) * (b[j] - '0');

    for (int i = 0; i < a.length() + b.length() - 1; i++)
    {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }

    reverse(c.begin(), c.end());

    while (c[0] == 0)
        c.erase(c.begin());

    for (int i = 0; i < c.size(); i++)
        result += c[i] + '0';

    cout << result << endl;

    return 0;
}
