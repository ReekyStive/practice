#include <iostream>
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
    int j;

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

    gen(b);

    if (a % 2 == 0)
        a++;

    for(int i = a; i <= b; i += 2)
    {
        if (notprim[i])
            continue;
        if (palin(i))
            cout << i << endl;
    }
    
    return 0;
}
