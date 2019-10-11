#include <iostream>
#include <string>

using namespace std;

string ss[1000];

bool match(string& str1, string& str2)
{
    for (int i = 0; i < str1.length(); i++)
    {
        if (str2[i] == '_')
            continue;
        if (str1[i] != str2[i])
            return false;
    }

    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> ss[i];
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string qss;
        cin >> qss;
        int res = 0;
        for (int j = 0; j < n; j++)
        {
            if (match(ss[j], qss))
                res++;
        }
        cout << res << endl;
    }

    return 0;
}
