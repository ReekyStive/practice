#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

int main()
{
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        s.clear();
        cin.get();
        getline(cin, s);

        int res = -1;
        for (char i = 'a'; i <= 'z'; i++)
        {
            int cnt = count(s.begin(), s.end(), i);
            if (cnt > res)
                res = cnt;
        }

        cout << "Case #" << j << ": " << res << endl;
    }
    return 0;
}