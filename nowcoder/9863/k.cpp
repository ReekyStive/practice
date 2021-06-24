#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;
    getline(cin, s1);
    string s2;
    getline(cin, s2);

    int len = s1.length();

    int cnt_g = 0, cnt_h = 0;
    for (int i = 0; i < len; i++)
    {
        if (s1[i] != s2[i])
        {
            if (s1[i] == 'G')
                cnt_g++;
            else
                cnt_h++;
        }
    }

    int res = cnt_g > cnt_h ? cnt_g : cnt_h;

    cout << res << endl;

    return 0;
}