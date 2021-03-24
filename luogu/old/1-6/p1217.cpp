#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX_N = 10e8 + 1;
bool notprim[MAX_N];

bool palin(int num)
{
    int res = 0;
    int temp = num;
    while (temp != 0)
    {
        res *= 10;
        res += temp % 10;
        temp /= 10;
    }
    if (res == num)
        return true;
    else
        return false;
}

void gen(int max)
{
    int len;

    for (int i = 3; i <= max / 3 + 1; i += 2)
    {
        if (notprim[i])
            continue;
        
        for (int j = 3; j * i <= max; j += 2)
            notprim[i * j] = true;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;

    int len = floor(log10(b) + 1);
    if (len % 2 == 0)
    {
        len--;
        b = pow(10, len);
    }

    gen(b);

    if (a % 2 == 0)
        a++;

    for(int i = a; i <= b; i += 2)
    {
        if (i == 11)
            cout << i << endl;
        
        len = floor(log10(i) + 1);
        if (len % 2 == 0)
            i = pow(10, len) + 1;
        
        if (notprim[i])
            continue;
        if (palin(i))
            cout << i << endl;
    }
    
    return 0;
}
