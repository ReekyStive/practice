#include <iostream>
#include <string>

using namespace std;

string s[100];

bool match(string a, string b)
{
    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < b.length(); j++)
        {
            if (a[i] == b[j])
                return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> s[i];

        bool is = true;
        for (int i = 0; i < n / 2; i++)
        {
            if (!match(s[i], s[n - 1 - i]))
            {
                is = false;
                break;
            }
        }

        if (is)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}