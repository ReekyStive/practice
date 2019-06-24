#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    int n;
    string ss;
    cin >> n >> ss;

    while (n >= 26)
        n -= 26;

    for (int i = 0; i < ss.size(); i++)
    {
        if (ss[i] >= 'a' && ss[i] <= 'z')
        {
            if ((int)ss[i] + n > 'z')
                ss[i] -= 26;
            ss[i] += n;
        }
        else
        {
            ss[i] += n;
            if ((int)ss[i] + n > 'Z')
                ss[i] -= 26;
            ss[i] += n;
        }
    }

    cout << ss;
    system("pause");

    return 0;
}
