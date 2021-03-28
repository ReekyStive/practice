#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void lower(string &str)
{
    for (int i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);
}

bool match(string &a, string &b, int loc)
{
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[loc + i])
            return false;
    }
    return true;
}

long long solve(string &a, string &b)
{
    int lena = a.length();
    int lenb = b.length();
    long long res = 0;
    for (int i = 0; i <= lenb - lena; i++)
    {
        if (match(a, b, i))
            res++;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    int n, m;
    string stra, strb;
    while (t--)
    {
        stra.clear();
        strb.clear();
        cin >> n >> m;
        cin >> stra >> strb;
        lower(stra);
        lower(strb);
        long long res = solve(stra, strb);
        cout << res << endl;
    }

    return 0;
}
