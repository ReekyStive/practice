#include <iostream>
#include <string>

using namespace std;
const int kMaxN = 8000;
int count[kMaxN];

int main()
{
    string tmp_str;
    string str;

    cin >> tmp_str;

    for (int i = 0; i < tmp_str.length(); i++)
    {
        if (tmp_str[i] == 'C' || tmp_str[i] == 'H' || tmp_str[i] == 'N')
            str += tmp_str[i];
    }

    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == 'N')
        {
            for (int j = i; j >= 0; j--)
            {
                count[j]++;
            }
        }
    }

    long long res = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'C')
        {
            for (int j = i + 1; j < str.length(); j++)
            {
                if (str[j] == 'H')
                {
                    res += count[j];
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}