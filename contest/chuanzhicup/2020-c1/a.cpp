#include <iostream>

using namespace std;

int calc(int n)
{
    int res = 0;
    while (n != 0)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (calc(i) == 9)
            res++;
    }

    cout << res << endl;

    return 0;
}
