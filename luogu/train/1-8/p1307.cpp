#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    if (str == "-0" || str == "0")
        cout << 0 << endl;
    else
    {
        bool minus = false;
        if (str[0] == '-')
            minus = true;

        if (minus)
            cout << '-';
        
        int start;
        for (start = str.length() - 1; start >= minus; start--)
        {
            if (str[start] != '0')
                break;
        }

        for (int i = start; i >= minus; i--)
            cout << str[i];
        cout << endl;
    }

    return 0;
}
