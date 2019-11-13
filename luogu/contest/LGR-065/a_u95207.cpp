#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;

    cin >> s;

    int tmp = 0, res = -1;
    bool haszero = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            tmp++;
            haszero = true;
        }
        else
            tmp--;

        if (tmp < 0)
            tmp = 0;

        res = max(res, tmp);
    }

    if (!haszero)
        res = -1;

    cout << res << endl;

    return 0;
}