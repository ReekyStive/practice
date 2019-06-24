#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int i, n, temp;
    cin >> n;
    int val[n];

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp > 50)
        {
            n--;
            i--;
            continue;
        }
        val[i] = temp;
    }

    
    // for (i = 0; i < n; i++)
    //     cout << val[i] << " ";
    
    system("pause");
    return 0;
}