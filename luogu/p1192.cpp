#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 100003;
const int maxn = 100000 + 2;
int s[maxn];

int main()
{
    int n, k;
    cin >> n >> k;
    
    s[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
            if (i - j >= 0)
                s[i] += s[i - j];
        
        s[i] %= mod;
    }
    cout << s[n] << endl;

    system("pause");
    return 0;
}