// Not Tested

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    ostringstream ostr;

    for (int i = 1; i <= k; i++)
    {
        if (i == k)
            ostr << 1 << " ";
        else
            cout << i + 1 << " ";
    }

    for (int i = k + 1; i <= n; i++)
    {
        cout << i << " ";
    }

    string str = ostr.str();
    str.erase(str.end() - 1);
    cout << str << endl;

    return 0;
}