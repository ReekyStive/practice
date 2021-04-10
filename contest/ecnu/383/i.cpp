#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string s, t;
    getline(cin, s);
    getline(cin, t);

    int i, j;
    j = 0;
    for (i = 0; i < t.length(); i++)
    {
        while (s[j] != t[i])
        {
            j++;
            if (j >= s.length())
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
