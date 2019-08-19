#include <iostream>

using namespace std;

int mem[21][21][21];

int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);

    if (mem[a][b][c] != 0)
        return mem[a][b][c] - 1;
    
    return (mem[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c)
        + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1) + 1) - 1;
}

int main()
{
    long long ina, inb, inc;
    int argua, argub, arguc;

    while (true)
    {
        cin >> ina >> inb >> inc;
        if (ina == -1 && inb == -1 && inc == -1)
            return 0;
        
        argua = ina > 20 ? 30 : ina;
        argub = inb > 20 ? 30 : inb;
        arguc = inc > 20 ? 30 : inc;

        cout << "w(" << ina << ", " << inb << ", " << inc << ") = "
            << w(argua, argub, arguc) << endl;
    }

    return 0;
}
