#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string a, b;
    getline(cin, a);
    getline(cin, b);

    int len = max(a.length(), b.length());
    string c;
    c.resize(len);

    for (int i = 0; i < len; i++)
    {
        int index_a = a.length() - i - 1;
        int index_b = b.length() - i - 1;
        int index_c = len - i - 1;

        int tmp_a = 0, tmp_b = 0;
        if (index_a >= 0)
            tmp_a = a[index_a] - '0';
        if (index_b >= 0)
            tmp_b = b[index_b] - '0';

        c[index_c] = (tmp_a + tmp_b) % 10 + '0';
    }

    while (c.length() > 1 && c[0] == '0')
    {
        c.erase(c.begin(), c.begin() + 1);
    }

    cout << c << endl;
}