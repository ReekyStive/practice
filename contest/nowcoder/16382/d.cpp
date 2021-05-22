#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    bool valid = true;
    if (k % 2 == 1)
        valid = false;

    if (valid)
    {
        string s;
        cin >> s;

        for (int i = 0; i < k; i++)
        {
            if (!valid)
                break;

            char temp = '?';
            for (int j = 0; i + k * j < n; j++)
            {
                if (s[i + k * j] != '?')
                {
                    temp = s[i + k * j];
                    break;
                }
            }
            if (temp != '?')
            {
                for (int j = 0; i + k * j < n; j++)
                {
                    if (s[i + k * j] == '?')
                        s[i + k * j] = temp;
                    else if (s[i + k * j] != temp)
                    {
                        valid = false;
                        break;
                    }
                }
            }
        }

        if (valid)
        {
            int cnt_0 = 0, cnt_1 = 0;
            for (int i = 0; i < k; i++)
            {
                if (s[i] == '0')
                    cnt_0++;
                if (s[i] == '1')
                    cnt_1++;
            }
            int cnt_2 = k - cnt_0 - cnt_1;
            if (abs(cnt_0 - cnt_1) > cnt_2)
                valid = false;
        }
    }

    if (valid)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
