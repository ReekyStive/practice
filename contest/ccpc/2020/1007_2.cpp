#include <iostream>
#include <vector>
using namespace std;

vector<int> v(26);

int main()
{
    int t;
    cin >> t;
    cin.get();
    for (int j = 1; j <= t; j++)
    {
        for (int i = 0; i < 26; i++)
            v[i] = 0;

        char c;
        while(cin.get(c), c != '\n')
            v[int(c - 'a')]++;

        int res = -1;
        for (int i = 0; i < 26; i++)
            if (v[i] > res)
                res = v[i];

        cout << "Case #" << j << ": " << res << endl;
    }
    return 0;
}