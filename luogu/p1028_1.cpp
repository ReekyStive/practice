#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

int bit(int n)
{
    return (log10(n) + 1);
}

int fbit(int n)
{
    return (n / pow(10, bit(n) - 1));
}

int fn(int n)
{
    int a = 0, f = fbit(n), ne;
    if (f == 1)
        return 0;
    
    for (int i = 1; i <= f/2; i++)
    {
        ne = (i * pow(10, bit(n)) + n);
        cout.width(8);
        cout << ne << endl;
        a++;
        a += fn(ne);
    }

    return a;
}

int main()
{
    int n, c;

    cin >> n;
    cout << "=========" << endl;
    cout.width(8);
    cout << n << endl;
    c = fn(n) + 1;
    cout << "=========" << endl;
    cout << c << endl;

    system("pause");
    return 0;
}
